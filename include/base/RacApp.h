#ifndef RACAPP_H
#define RACAPP_H

#include "MooseApp.h"

class RacApp;

template<>
InputParameters validParams<RacApp>();

class RacApp : public MooseApp
{
public:
  RacApp(InputParameters parameters);
  virtual ~RacApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* RACAPP_H */
