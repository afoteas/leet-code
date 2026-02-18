#!/usr/bin/env python3
"""
Script to automatically update difficulty tags in README.md when new problem folders are added.
Run this script whenever you add a new problem folder to the workspace.
"""

import os
import re
import json
import subprocess
from pathlib import Path
from typing import Dict, Set, Optional


class DifficultyUpdater:
    """Updates difficulty tags for LeetCode problems in README.md"""
    
    def __init__(self, workspace_root: str):
        self.workspace_root = Path(workspace_root)
        self.readme_path = self.workspace_root / "README.md"
        self.stats_path = self.workspace_root / "stats.json"
        
    def get_existing_problems(self) -> Set[str]:
        """Get set of problem IDs from folder structure"""
        problems = set()
        for item in self.workspace_root.iterdir():
            if item.is_dir():
                # Match pattern: XXXX-problem-name
                if re.match(r'^\d{4}-', item.name):
                    problems.add(item.name)
        return problems
    
    def get_problem_difficulties(self) -> Dict[str, str]:
        """Extract difficulty mapping from existing README sections"""
        difficulties = {}
        
        # Build mapping from README (problems with difficulty tags)
        if self.readme_path.exists():
            with open(self.readme_path, 'r') as f:
                content = f.read()
                # Find problems with difficulty tags: [0001-problem-name](url) **Difficulty**
                # Only match if **Difficulty** is actually present
                pattern = r'\[(\d{4}-[^\]]+)\]\([^)]+\)\s+\*\*(Easy|Medium|Hard)\*\*'
                for match in re.finditer(pattern, content):
                    problem_id = match.group(1)
                    difficulty = match.group(2)
                    difficulties[problem_id] = difficulty
        
        return difficulties
    
    def get_problems_missing_tags(self) -> Set[str]:
        """Find all unique problem IDs in README that are missing difficulty tags"""
        if not self.readme_path.exists():
            return set()
        
        with open(self.readme_path, 'r') as f:
            content = f.read()
        
        # Find all problem IDs mentioned in links
        all_problem_ids = set(re.findall(r'\[(\d{4}-[^\]]+)\]\(', content))
        
        # Find problem IDs that have difficulty tags
        problems_with_tags = set(re.findall(r'\[(\d{4}-[^\]]+)\]\([^)]+\)\s+\*\*(Easy|Medium|Hard)\*\*', content))
        
        # Return problems that don't have tags
        return all_problem_ids - problems_with_tags
    
    
    def get_difficulty_from_problem_readme(self, problem_id: str) -> Optional[str]:
        """
        Try to extract difficulty from the problem's own README.md file.
        Looks for <h3>Easy|Medium|Hard</h3> or **Easy|Medium|Hard** patterns.
        """
        problem_dir = self.workspace_root / problem_id
        readme_path = problem_dir / "README.md"
        
        if not readme_path.exists():
            return None
        
        try:
            with open(readme_path, 'r') as f:
                content = f.read()
            
            # Try to find difficulty in HTML header format: <h3>Difficulty</h3>
            html_match = re.search(r'<h3>(Easy|Medium|Hard)</h3>', content)
            if html_match:
                return html_match.group(1)
            
            # Try to find difficulty in markdown format: **Difficulty**
            md_match = re.search(r'\*\*(Easy|Medium|Hard)\*\*', content)
            if md_match:
                return md_match.group(1)
        except Exception as e:
            pass
        
        return None
    
    def get_difficulty_for_problem(self, problem_id: str, existing_difficulties: Dict[str, str]) -> Optional[str]:
        """
        Get difficulty for a problem, checking multiple sources.
        Returns None if not found and needs manual input.
        """
        # Check if already in difficulties map
        if problem_id in existing_difficulties:
            return existing_difficulties[problem_id]
        
        # Try to extract from problem's own README.md
        difficulty = self.get_difficulty_from_problem_readme(problem_id)
        if difficulty:
            return difficulty
        
        return None
    
    def prompt_for_difficulty(self, problem_id: str) -> str:
        """Prompt user for difficulty if not found"""
        print(f"\n⚠️  Cannot determine difficulty for: {problem_id}")
        print("   Options: Easy, Medium, Hard")
        
        while True:
            choice = input(f"   Enter difficulty for {problem_id} (E/M/H): ").strip().upper()
            if choice == 'E':
                return 'Easy'
            elif choice == 'M':
                return 'Medium'
            elif choice == 'H':
                return 'Hard'
            else:
                print("   Invalid choice. Please enter E, M, or H.")
    
    def update_problem_difficulties(self, problems_to_fix: Set[str], difficulty_map: Dict[str, str]) -> bool:
        """Update README with difficulty tags for all problems"""
        if not self.readme_path.exists():
            print(f"❌ README not found at {self.readme_path}")
            return False
        
        with open(self.readme_path, 'r') as f:
            content = f.read()
        
        original_content = content
        updated_count = 0
        
        for problem_id in sorted(problems_to_fix):
            if problem_id not in difficulty_map:
                print(f"⏭️  Skipping {problem_id} - difficulty not determined")
                continue
            
            difficulty = difficulty_map[problem_id]
            
            # Pattern to match problem links WITHOUT difficulty tags
            # | [problem-id](url) | (must end with just |, no **difficulty**)
            pattern = rf'(\| \[{re.escape(problem_id)}\]\([^)]+\)) \|(?!\s*\*\*)'
            replacement = rf'\1 **{difficulty}** |'
            
            # Perform replacement for all occurrences
            new_content, count = re.subn(pattern, replacement, content)
            
            if count > 0:
                content = new_content
                updated_count += count
                print(f"✅ Updated {problem_id}: {count} occurrence(s) - **{difficulty}**")
            # else:
            #     # Check if it already has difficulty tag
            #     if re.search(rf'\[{re.escape(problem_id)}\]\([^)]+\) \*\*', content):
            #         print(f"ℹ️  {problem_id} already has difficulty tag")
        
        if content != original_content:
            with open(self.readme_path, 'w') as f:
                f.write(content)
            print(f"\n✨ Successfully updated README.md with {updated_count} difficulty tag(s)")
            return True
        else:
            print(f"\nℹ️  No changes needed - all problems already have difficulty tags")
            return False
    
    def run(self, interactive: bool = True):
        """Main method to run the updater"""
        print("🚀 LeetCode README Difficulty Updater\n")
        
        # Get existing problems from folders
        existing_problems = self.get_existing_problems()
        print(f"📁 Found {len(existing_problems)} problem folders")
        
        # Get existing difficulty mapping (problems with tags)
        existing_difficulties = self.get_problem_difficulties()
        print(f"📊 Found {len(existing_difficulties)} problem links with difficulty tags in README")
        
        # Find problems in README that are missing difficulty tags
        problems_missing_tags = self.get_problems_missing_tags()
        print(f"⚠️  Found {len(problems_missing_tags)} problems missing difficulty tags")
        
        # Find problems that exist in folders but aren't in README at all
        if self.readme_path.exists():
            with open(self.readme_path, 'r') as f:
                content = f.read()
            all_readme_problems = set(re.findall(r'\[(\d{4}-[^\]]+)\]\(', content))
        else:
            all_readme_problems = set()
        
        problems_not_in_readme = existing_problems - all_readme_problems
        print(f"📝 Found {len(problems_not_in_readme)} new problem folders\n")
        
        if not problems_missing_tags and not problems_not_in_readme:
            print("✅ All problems already have difficulty tags!")
            return
        
        if problems_missing_tags:
            print(f"Missing difficulty tags:")
            for problem_id in sorted(problems_missing_tags):
                print(f"   - {problem_id}")
        
        if problems_not_in_readme:
            print(f"\nNew problem folders:")
            for problem_id in sorted(problems_not_in_readme):
                print(f"   - {problem_id}")
        
        # Build difficulty map for problems needing update
        difficulty_map = {}
        all_problems_to_fix = problems_missing_tags | problems_not_in_readme
        
        if interactive:
            print("\n" + "="*60)
            for problem_id in sorted(all_problems_to_fix):
                # For missing tags, try to use existing difficulty from another instance
                if problem_id in problems_missing_tags and problem_id in existing_difficulties:
                    difficulty = existing_difficulties[problem_id]
                    difficulty_map[problem_id] = difficulty
                    print(f"ℹ️  Using existing difficulty for {problem_id}: **{difficulty}**")
                else:
                    difficulty = self.get_difficulty_for_problem(problem_id, existing_difficulties)
                    if not difficulty:
                        difficulty = self.prompt_for_difficulty(problem_id)
                    difficulty_map[problem_id] = difficulty
        else:
            print("\n⚠️  Non-interactive mode: checking for existing difficulties...")
            for problem_id in sorted(all_problems_to_fix):
                # Try to find difficulty from existing instances or lookup
                if problem_id in existing_difficulties:
                    difficulty = existing_difficulties[problem_id]
                else:
                    difficulty = self.get_difficulty_for_problem(problem_id, existing_difficulties)
                
                if difficulty:
                    difficulty_map[problem_id] = difficulty
        
        # Update README
        if difficulty_map:
            print("\n" + "="*60)
            print("Updating README.md...\n")
            self.update_problem_difficulties(all_problems_to_fix, difficulty_map)
        else:
            print("\n⚠️  No difficulties determined - no updates made")


def main():
    """Entry point for the script"""
    import sys
    
    # Parse arguments
    workspace_root = os.getcwd()
    interactive = True
    
    for arg in sys.argv[1:]:
        if arg == '--non-interactive':
            interactive = False
        elif not arg.startswith('--'):
            workspace_root = arg
    
    # Check if this is a valid workspace
    if not Path(workspace_root).exists():
        print(f"❌ Error: Path does not exist: {workspace_root}")
        sys.exit(1)
    
    # Run the updater
    updater = DifficultyUpdater(workspace_root)
    updater.run(interactive=interactive)


if __name__ == "__main__":
    main()
