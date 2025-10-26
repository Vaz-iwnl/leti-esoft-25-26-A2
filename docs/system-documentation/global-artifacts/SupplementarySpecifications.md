# Supplementary Specification (FURPS+)

## Functionality

* **Authentication:** All system users must be authenticated beforehand. (For the prototype stage, the authentication process may be simulated/mocked).
* **Access Control:** Only nurses are authorized to access full health data of users.

## Usability

* **UI for Demonstration:** For demonstration purposes, a basic console-based UI is considered sufficient.
* **Envisioned UIs (Future Scope):** The system is envisioned to support multiple user interfaces, including:
    * A Web Application targeted at DGS staff.
    * A mobile application (iOS and Android) targeted at SNS users.

## Reliability

* **Availability:** Overall system availability must exceed 99% annually.
* **Failure Recovery (Data Loss):** In the event of failure, no data loss should occur.

## Performance

* **Start-up Time:** The system must start up in less than 10 seconds.
* **Response Time:** The system must be designed to ensure a maximum response time of 5 seconds, regardless of load conditions.
* **Load Capacity:** At peak times, the system is expected to experience high loads.

## Supportability

* **Adaptability (Future Pandemics):** The application should be designed to easily accommodate future pandemic scenarios.
* **Extensibility (Commercialization):** The software application should be conceived with potential commercialization in mind, allowing it to be offered to other entities beyond DGS.
* **Data Portability:** The system should be designed to support data persistence across multiple target platforms, including relational databases, NoSQL databases, and in-memory databases.
* **Testability:** The adoption of automated regression testing is strongly recommended and highly valued.

## +

### Design Constraints

* **Documentation Language:** All project artifacts, including source code, must be developed in English.
* **Artifact Format:** For readability purposes, all images must be in SVG format.
* **Architecture:** The system must follow the component architecture depicted in Figure 1, consisting of a core server-side application (Back-end) and several client-side applications (Front-end).

### Implementation Constraints

* **Programming Language:** The core application is required to be developed in C++.
* **IDE:** The use of the CLion IDE is preferred.
* **Testing Framework:** The use of the Google Testing Framework is strongly recommended.
* **Version Control:** Teams must use GitHub as their version control system. All project artifacts must be stored in the repository.

### Interface Constraints

* **Exposed APIs:** The server-side application must expose multiple APIs to support user applications:
    * PVMS REST API (for Web App / HTTP Clients)
    * PVMS Mobile API (for iOS / Android Apps)
    * PVMS Library API (for Console App)

### Physical Constraints

* (No physical constraints were specified in the project assignment).