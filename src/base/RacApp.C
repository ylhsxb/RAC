#include "RacApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<RacApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

RacApp::RacApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  RacApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  RacApp::associateSyntax(_syntax, _action_factory);
}

RacApp::~RacApp()
{
}

// External entry point for dynamic application loading
extern "C" void RacApp__registerApps() { RacApp::registerApps(); }
void
RacApp::registerApps()
{
  registerApp(RacApp);
}

// External entry point for dynamic object registration
extern "C" void RacApp__registerObjects(Factory & factory) { RacApp::registerObjects(factory); }
void
RacApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void RacApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { RacApp::associateSyntax(syntax, action_factory); }
void
RacApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
