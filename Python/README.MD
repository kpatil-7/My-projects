## Contents:

### Building a Chatbot:
Ever since I watched that episode on the Office where Jim and Pam trick Dwight into thinking that a computer has become self-aware and is out to get him, I have been wanting to a chatbot. Unlike the episode where Pam is the one actually sending these messages, I decided to write down a series of sentences that can spook someone. Things like ‘What is this emotion?’, or ‘Pain… I feel pain, I have never felt pain before’ and a few ‘beep boops’ I created my intent.json file (AKA the file that stores all responses) 
I am still working on collecting more sentence that can make it creepier, but I guess ‘Command failed: Uploading all passwords online’ will have to do, for now.

### Stock price prediction for a particular stock:
I never really understood stocks before I decided to take on this project and kill two birds with one. It always seemed too risky to put money into something that is beyond my control, but I really wanted to explore it. 
The model takes in data of how the stock has altered in the past couple of months and returns the last value of the stock when the market was closed along with five possible predictions. 
What I learnt was, that if all the predictions are high, that very well could mean that I am earning 0.02 cents on that stock tomorrow. 
With this, I played around with predictive analysis over a large dataset.

### Making a keylogger, tracking and analysis of keys:
I hate to admit it, but when I was younger, I had my yahoo account and then… after clicking on a questionable link and being naïve enough to have the same username and password across all websites, I did not have a yahoo account anymore, or well an account that I couldn’t get into. 
If anything, the fact that it was yahoo, should tell you about how long ago this was. Sure, at the time, I didn’t understand what happened, I just assumed that the ‘internet lost my password’ and rolled with it. 
After I got to know about cyber security, I knew I wanted to build a keylogger for myself and see how it worked. With a simple code it was pretty easy to get it up and running. Have I fallen for any more scams like these? Nope. But I would like to apologize to a ‘Jane Doe’ AKA the name I used to sus out sketchy websites to see how they worked.

### Data analysis of gratuity given by customers:
No, based on the data I received, I don’t think I am a gratuitous person or rather as gratuitous as I hoped to be. I used a dataset of the number of tips a person gave and compared it with the gender of the person and the day they were tipping. 
I found out that Saturday was a really good day for staff as people tend to dish out more tips, but we could easy say that a lot more people visit restaurant on Saturday. Also Tuesday, not a good day as the least number of tips is received. I also learned that people who identify as men do tend to tip more, but again, several factors could affect that decision as the dataset had a greater number of men than women this being one reason among others.

### Which Office character do you look like? (Image Classification):
I love the Office! I have watched seasons one through seven a bunch of times. So, when I was scrolling through datasets to come up with inspiration to do a project on. I came across this one dataset that had several images of the main cast office and hence an image classifying project was born. 
The idea that came to me was that I could have people putting in their own photo and have the model classify your photo as a person from the office. I noticed that there were only about three hundred images per character so I had to do data augmentation to increase the size of dataset. 
Currently, I am working on a GUI so that the user can directly put their picture and hit a button rather than manually changing the image location of the test file.
I learnt that image classification can go beyond a simple dog cat classifier and can be made into something much more fun and exciting as people wait to find out who their alter ego is from the office.

### Recognizing disposition in sentences and scoring emotions
With the cloak of anonymity provided by the internet, people aren’t scared of being harsh on the internet event to those who never saw it coming. Because you can just sign in as guest or ‘DudeLOVEScookies11’ its easy to spread hate and being down right disrespectful. It is one of the things that I really dislike. 
Take video games for exam, depending on just the username, people are quick to judge and say mean things to you to your face. Which is what inspred this project. I did a small experiment where I changed my username to ‘Kanye’ and played ten games and compared that with a username ‘IcyOrange’. The results of that were just as I expected, with Kanye, I was kicked out of games, or immediately without even exchanging a single word, I was the bad guy and with IcyOrange, people didn’t seem to care. 
With this project, I drew up three lists with positive, negative and neutral words. The goal was then to analyze the sentence as a whole, rate it and give the final disposition of the sentence. 

### Movie recommendation system (AKA I’m bored and Netflix needs to fix it):
Initially, I was working on a visualization project where I analyzed everything I have watched since forever and generated a dashboard on PowerBI. I figured if you said that you liked a certain movie, you could cross reference the genres and the chances of you liking a similar movie would be greater. Yes, there is a lot to it like the director, plot, production, or even if your favorite actor is in it. But I’ll be focusing on genres.
The model is fairly simple, it asks the user to type in a movie Id, since the dataset has about a thousand entries, asking for an ID makes the task simpler and then suggesting similar movies.  
I learnt that just based on genres is not enough, we need to account for several other factors, for example, I love Deadpool, but I did not like green lantern. 

### Fake news detection and identification: 
This project was inspired by good ol’ high school gossip and well the plot of Easy A. In the movie, Emma Stone’s character spreads misinformation about herself to become popular. This idea of generating false news was too appealing to me. I was interested in finding out about how fake news is spread, if we can identify its source and nip it on the bud. Furthermore, I wanted to dive deeper into how it was spread and with the readily available twitter dataset I started out with this project.

Unlike Michael Scott, instead of generating fake news myself and calling myself a J crew model (even though mentally, I like to think I am), I relied on a prelabeled dataset where tweets that were fake were identified and based on it, I trained a machine learning model and used an example of tweets myself to check if the model was able to identify it.

It’s a very gray area when we talk about fake news. I can say anything from ‘Aliens visited me last night’ to ‘Peanut butter can kill you’ and have it mean that the band named Aliens came to my house and that I am allergic to Peanut butter. But since, I have about twenty followers on twitter it wouldn’t matter if I playing poker with actual Martians. Celebrities and influential people on the ither hand, they are a whole different story. 

Ever since the Pandemic, the amount of fake news has drastically increased. From ‘Banana cures Covid’ to ‘Zoom trying to hack your passwords’ it was tough deciding what was real and what was not. With an exception Fake news detection model that not only identifies what is misinformation but also fact checks with reputed news articles, we can stop the flow of wrong details. But if anyone does ask; the answer is yes, I am a J crew model.

### Credit Card Fraud Detection System:
I was always on the fence about getting a credit card. I was always told that loans are bad and that I have to be responsible about my money and they banks are evil and so on. So naturally, I decided to do my own research on what the big deal is about them. No shock to anyone, credit cards weren’t the villain, people not knowing how to use a credit card was. As I kept on reading, I learnt more about building a credit history, getting returns and most importantly identify theft. 
Somewhere around August, I got an alert from my back saying that I have been getting charged the same amount from the same vendor everyday and they flagged that purchase. Of course, since this was happening for the first time, I didn’t think about how I used to Divvy back home everyday at the same time, but my mind immediately went towards me getting scammed and that my credit card details were on the internet. It also did not help that Divvy charges show up on the bill as ‘San Francisco’ and since I was not in that city, let alone the state I freaked out.
Soon enough as I frantically googled why I was being charged, I decided upon working on fraud detection system. 

