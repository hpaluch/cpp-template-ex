C++ example to show side effects of macros/operators
====================================================

This example shows possible side effects when using preprocessor macros
and/or modifying operators.


Setup on Ubuntu 14
======================

As root or via sudo install:

	apt-get install eclipse-cdt libstdc++-4.8-dev make g++

As unprivileged user issue:

	mkdir ~/projects
	cd ~/projects
	git clone https://github.com/hpaluch/cpp-template-ex.git

Build/Run with Eclipse CDT (GUI)
--------------------------------
These instructions apply when running Eclipse as GUI application
(under X-Window):

* Run Eclipse (for example using 'eclipse' from cmd line
* In project explorer choose Import ...
* Select General -> Existing Projects into Workspace, Next
* Select root directory - Browse .. to directory containing cloned project
  ( ~/projects/cpp-template-ex )
* Issue Ctrl-B to build this project
* Issue "Run cpp-template-ex" to run this projects
  (or use Ctrl-F11, but not in Openbox manager)
* See Console view and comments in code


Build/Run with Eclipse CDT (CLI)
--------------------------------
These instructions apply when running Eclipse
from Command Line (CLI) - no GUI required:

Issue as unprivileged user:

	rm -rf ~/tmp/tmpws
	mkdir -p ~/tmp/tmpws
	eclipse -nosplash  \
	   -application org.eclipse.cdt.managedbuilder.core.headlessbuild \
	   -import file://$HOME/projects/cpp-template-ex \
	   -build  cpp-template-ex \
	   -data ~/tmp/tmpws

Run compiled binary:

	~/projects/cpp-template-ex/Release/cpp-template-ex

Note: once you have done 1st eclipse build you can rebuild code just issuing:

	cd ~/projects/cpp-template-ex/Release
	make all
	./cpp-template-ex

Resources
=========

* headless Eclipse build example taken from: http://stackoverflow.com/questions/344797/build-several-cdt-c-projects-from-commandline

