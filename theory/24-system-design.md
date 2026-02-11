# System Design

## Overview
High-level architectural design for scalable, reliable systems.

## Key Concepts

### Scalability
- **Vertical Scaling**: Add more resources to single machine
- **Horizontal Scaling**: Add more machines
- **Load Balancing**: Distribute traffic across servers

### Availability
- **Redundancy**: Multiple instances
- **Failover**: Automatic switching to backup
- **Monitoring**: Health checks and alerts

### Consistency
- **Strong Consistency**: All nodes see same data at same time
- **Eventual Consistency**: Nodes eventually sync
- **CAP Theorem**: Can only guarantee 2 of Consistency, Availability, Partition Tolerance

## Common Components

### Load Balancer
- Distributes incoming requests
- Health checking
- Algorithms: Round robin, least connections, IP hash

### Cache
- **Redis**, **Memcached**
- Cache-aside, write-through, write-behind
- LRU, LFU eviction policies

### Database
- **SQL**: ACID, relational (PostgreSQL, MySQL)
- **NoSQL**: Scalable, flexible schema (MongoDB, Cassandra)
- **Sharding**: Partition data across databases
- **Replication**: Master-slave, master-master

### Message Queue
- **Kafka**, **RabbitMQ**
- Asynchronous communication
- Decoupling services

### CDN (Content Delivery Network)
- Distribute static content
- Edge locations close to users

## Design Patterns

### Microservices
- Small, independent services
- Domain-driven design
- API gateway

### Event-Driven Architecture
- Services communicate via events
- Eventual consistency
- Loose coupling

## Common Interview Questions
1. Design URL shortener
2. Design Twitter/Facebook feed
3. Design Instagram
4. Design Uber
5. Design messaging system (WhatsApp)
6. Design video streaming (Netflix)
7. Design web crawler
8. Design rate limiter

## Interview Approach
1. **Clarify requirements**: Users, traffic, features
2. **Estimate scale**: QPS, storage, bandwidth
3. **High-level design**: Components, data flow
4. **Deep dive**: Specific component details
5. **Identify bottlenecks**: Scale, reliability
6. **Discuss tradeoffs**: Consistency vs availability

[← Back to README](README.md)
