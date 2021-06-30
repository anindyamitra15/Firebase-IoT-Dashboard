#### There are just a few really easy steps to get your IoT web dashboard running on firebase:
Below are the instructions, just follow those and you're good to go:<br><br>
* Go to the [Firebase console page](https://console.firebase.google.com/) first create an account and Click on create project<br><br>
<img src="https://user-images.githubusercontent.com/55695557/123162962-d477d600-d48e-11eb-9917-c9bb683047aa.png" width="80%">
* Enter a suitable project name for your project and click continue<br><br>
<img src="https://user-images.githubusercontent.com/55695557/123163501-67187500-d48f-11eb-83de-7d3a860fa3c5.png" width="80%">
* You may enable google analytics as per your choice and continue<br><br>
<img src="https://user-images.githubusercontent.com/55695557/123163644-916a3280-d48f-11eb-8f4a-b5b4415b7392.png"  width="80%">
* Choose a location (This represents the country/region of your organization. This does not affect where Google may process and store Customer Data for Firebase.)<br><br>
<img src="https://user-images.githubusercontent.com/55695557/123163816-c5455800-d48f-11eb-98a7-db6fc0f04cae.png" width="80%">
* Create Project, wait till the project gets created...<br><br>
<img height="100%" width="50%" display="inline" src = "https://user-images.githubusercontent.com/55695557/123164103-1f461d80-d490-11eb-9101-25571ad53986.png"/>
* Continue:<br><br>
<img height="100%" width="50%" display="inline" src = "https://user-images.githubusercontent.com/55695557/123164145-2ec56680-d490-11eb-8764-187354949587.png"/>

* You will be able to see your project console page:<br><br>
![image](https://user-images.githubusercontent.com/55695557/123164614-d04cb800-d490-11eb-895f-faee93bc30c0.png)

* Under Project Overview tab on the left side of the page, go to Build -> Hosting:<br><br>

![image](https://user-images.githubusercontent.com/55695557/123164751-fd00cf80-d490-11eb-94d5-1ae7e75a0167.png)

* Get started with hosting:<br><br>

![image](https://user-images.githubusercontent.com/55695557/123165122-700a4600-d491-11eb-9a3d-5f303b168a9f.png)

* Just follow the steps one by one, firebase itself will guide you very well, but thing to note, you would like to install node(if you don't have it already) from here, which includes the tool `npm` that we need (choose the LTS version and the package according to your OS, to start with): https://nodejs.org/en/ -See their documentation/guides for setting path and environmental variables<br><br>

![image](https://user-images.githubusercontent.com/55695557/123638528-e796f700-d83c-11eb-9603-2ce50e24423e.png)

* You may now open a new folder in VS code dedicated for your project, press `ctrl + shift + ~` to open terminal and starting putting the commands you see there/below.
* You will need to login locally to be able to push changes to the hosted site/web-app when you are deploying:<br><br>
![image](https://user-images.githubusercontent.com/55695557/123638826-3cd30880-d83d-11eb-877d-dd78a350f64b.png)
    1. Logging in `firebase login`: type in the command and press (Y/n) as per your choice:<br><br>
![image](https://user-images.githubusercontent.com/55695557/123638752-24fb8480-d83d-11eb-8135-2e988c8b2fd0.png)
    2. Firebase will take you to the authorization page, from there choose your google account on which you were building the firebase project and Allow, after login succeeds, the page will show something like this:<br><br>
<img src="https://user-images.githubusercontent.com/55695557/123639345-b66af680-d83d-11eb-9a8c-c41c441612fd.png" width="70%">

* Initializing firebase `firebase init`:<br><br>
![image](https://user-images.githubusercontent.com/55695557/123647084-6a23b480-d845-11eb-8ad2-8502edf1a169.png)
1. Press Y to contiue
2. Use arrow (`↑`/`↓`) keys to navigate and SpaceBar to select/deselct, finally press enter `↵` to proceed. We will need Realtime Database and Hosting as a minimum for our project, you may select other available choices as well (depends on your firebase plans Spark/Blaze)<br><br>
![image](https://user-images.githubusercontent.com/55695557/123647802-0948ac00-d846-11eb-91a5-9318b5c3d1af.png)
* Choose: Use an existing project<br><br>
![image](https://user-images.githubusercontent.com/55695557/123648962-08fce080-d847-11eb-81f2-1ff3a83cc2ed.png)
* You will see all your projects (present in your firebase account) listed<br><br>
![image](https://user-images.githubusercontent.com/55695557/123649166-2df15380-d847-11eb-8efc-1d484a597c07.png)
* Setup RTDB:<br><br>
![image](https://user-images.githubusercontent.com/55695557/123649548-74df4900-d847-11eb-802a-80f409f225fd.png)
* Choose a nearby location:<br><br>
![image](https://user-images.githubusercontent.com/55695557/123649744-9f310680-d847-11eb-9248-8c8d85b7c048.png)
* Press Enter `↵` to choose the default option:<br><br>
![image](https://user-images.githubusercontent.com/55695557/123649954-c982c400-d847-11eb-8244-eb85dc53e58f.png)
* Now you will have to choose a folder from where your page will be deployed, if you choose default, it will make a directory called `public` inside your current folder.
* See the options chosen below, you may choose as you like, however, in this project, I  have decided to make it a single page application without any git based automatic deployment (however you may try out, instructions not included here).<br><br>
![image](https://user-images.githubusercontent.com/55695557/123650419-35fdc300-d848-11eb-8f3e-b148ea8f40c0.png)
* Now, as you navigate through your projet folder, you will see a new folder called public and under it you will find a file called index.html, you can safely delete that file, as we have prepared an index.html file already.<br><br>
![image](https://user-images.githubusercontent.com/55695557/123651261-f2f01f80-d848-11eb-8787-a26e95e2ad5e.png)
* Now in [our](.) repository, you will find the necessary [index.html](./Webpage/index.html) page in the Webpage folder, copy that `index.html` and put it into the public folder inside your project folder.<br><br>
![image](https://user-images.githubusercontent.com/55695557/123652286-cbe61d80-d849-11eb-93d5-795b2fd598ee.png)
* Now almost everything is done, go to the console page, click next, copy the `firebase deploy` command and put it in the VS code terminal of in project folder and press enter `↵`. Note down the `Hosting URL`.<br><br>
![image](https://user-images.githubusercontent.com/55695557/123652849-4878fc00-d84a-11eb-90c2-ba684459d6f2.png)
* So you have successfully deployed your webpage on firebase hosting, now click on that URL and you will see that page. However there are still some minor steps left after hosting.<br><br>
![image](https://user-images.githubusercontent.com/55695557/123653215-955cd280-d84a-11eb-8752-baeafcaba1a1.png)

### Creating a Realtime Database
* Create a database<br><br>
![image](https://user-images.githubusercontent.com/55695557/123653772-161bce80-d84b-11eb-9cae-31e6ff03f566.png)
* After you have created your RTDB, you will see that the message saying "Connecting to server...!" on top of your webpage has vanished, which means your webpage has successfully connected to the database!<br><br>
![image](https://user-images.githubusercontent.com/55695557/123860094-18f9ea80-d943-11eb-82fa-7d2b492c1dbb.png)
* Now try toggling the switch and changing the slider a little bit, and observe your RTDB console, you will see a new object is present, which concludes that you are not able to write to the database from your webpage, congrats!🎉  <br>
### An important point for debugging and developing firebase web app: 
* While building the page, you may not want to deploy your page to firebase until it is ready, if that is the case, then you would want to host your webpage locally by using the command `firebase emulators:start` you will see the host and port in the terminal.<br><br>
![image](https://user-images.githubusercontent.com/55695557/123692074-02d12900-d874-11eb-8529-5d5f90df53ad.png)
* After you are done with debugging, just press `Ctrl+c` on your keyboard to interrupt and stop the local server and then you may deploy to push the changes.