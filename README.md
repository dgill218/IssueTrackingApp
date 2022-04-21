# IssueTrackingApp
Final project for CS3520 at Northeastern University. 

Classes: 
- Issue 
  - int issueId
  - enum issueType 
  - enum status 
  - string description 
  - string createdDate
  - string dueDate 
  - int completionPercentage
  - vector<int> assignees
- User 
  - int userId
  - string name
  - enum role 
  - vector<int> projectsAssigned
- TrackingBoard
  - vector<Issue> issues 
