/*
 * fMBT, free Model Based Testing tool
 * Copyright (c) 2011, 2012 Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU Lesser General Public License,
 * version 2.1, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include "config.h"
#ifdef WITH_JVM
#ifndef __aal_java_hh__
#define __aal_java_hh__

#include "aal.hh"
#include <jni.h>

class aal_java: public aal {
public:
  aal_java(Log&l,std::string&);
  virtual ~aal_java() {};

  virtual int adapter_execute(int action,const char* params);
  virtual int model_execute(int action);
  virtual int getActions(int** act);
  virtual bool reset();

  virtual void push();
  virtual void pop();
  virtual int getprops(int** props);
  virtual int observe(std::vector<int> &action, bool block = false);
private:
  JNIEnv *env;  
  JavaVM *jvm;

  JavaVMInitArgs vm_args;
  JavaVMOption options;

  jclass wclass;
  jobject obj;

  jmethodID constructor;
  jmethodID aexec;
  jmethodID mexec;
  jmethodID geta;
  jmethodID Reset;
  jmethodID Init;
  jmethodID Push;
  jmethodID Pop;
  jmethodID Getprops;
  jmethodID gettnames;
  jmethodID obs;
};


#endif
#endif
