# The goal of this repo
First of all the name of the repository is all wrong. The initial intention was to explore some different frameworks implementing RESTful APIs, see what is the state of the art when designing easily mainainable and scalable code base. Obviously, this scope is too large and this bacame apparent the moment I hit the random link https://github.com/oatpp/oatpp. Even just this library/framework has many example projects as separate repos. So what I expect to have here is a collection of my experiments with different example projects of Oat++ and maybe if something sticks it will get its own repo.

# What was the actual thing I did here
I followed the step-by-step tutorial from https://oatpp.io/docs/start/step-by-step/#simplest-project. And it would be tempting to just copy or fork the final repo from https://github.com/oatpp/oatpp-starter and pat myself on the back after reading it and understanding it (like oh so many did). Instead I chose to build the project from the ground up, get it working at each step and even get outside the defined best practices where I felt the framework is forcing me to use things I'm not comfortable with at this early stage of the exploration. This included:
* Setting up the VS solution and projects to use Oat++ as a static library.
* Working through each stage of the evolution of this little project.
* Juggling includes and sources until the file structure made sense.
* Avoiding the dependency injection (DI) framework of Oat++ as long as I could to see myself code into a corner and start liking it.
* Setting up an additional build target for unit tests in the same project of the VS just to see if I can make it.

# Lessons learned
Just by looking at this particular starter project it seems that all the work with the library has to be done by using an extensive macro web - there is just no other choice. At first the naive implementation of a service is shown for a brief moment just to move to all the components macro practices needed for the dependency injection. At some point it seemed like I could make some simpler implementation solving the issues DI solves but without scary macros. This failed spectacularly when I found out that the unit test implementation relies on a particular DI implemented by the library under the hood. For now the presented DI framework seems like global variables just the other way but I'll have to see how powerfull it really is by implementing some more interesting services.

# Warning!
This repository isn't meant for anyone to reproduce but this is how it would be done. After cloning it:
```
git submodule update --init
```
then follow instructions to build Oat++ on Windows https://oatpp.io/docs/installation/windows/ from the newly created submodule directory. All the paths in the project should be relaive and point to various dirs of this submodule, so it should work for anyone. When the solution builds it should build two targets (debug and test). The server and the endpoint will run just fine but the unit test will crash because of the reasons mentioned in previous section.