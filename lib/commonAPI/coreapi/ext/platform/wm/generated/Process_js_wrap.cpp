#include "IProcess.h"
#include "api_generator\js_helpers.h"

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "Process"

#include "common/StringConverter.h"

extern "C" void rho_wm_impl_performOnUiThread(rho::common::IRhoRunnable* pTask);

using namespace rho;
using namespace rho::json;
using namespace rho::common;


rho::String js_s_Process_runApplication(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::IRhoRunnable* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;



    nCallbackArg = 1;

    
    if ( argc == 0 )
    {
        oRes.setArgError(L"Wrong number of arguments: " + convertToStringW(argc) + L" instead of " + convertToStringW(3) );
        return oRes.toJSON();
    }
    


    rho::StringW arg0;
    if ( argc > 0 )
    {
        if ( argv[0].isString() )
        {
            arg0 = convertToStringW(argv[0].getString());

            oRes.setStringParam(argv[0].getString());

        }
        else if (!argv[0].isNull())
        {
            oRes.setArgError(L"Type error: argument " L"0" L" should be " L"string" );
            return oRes.toJSON();
        }
    }











        



    nCallbackArg = 2;

    


    rho::StringW arg1;
    if ( argc > 1 )
    {
        if ( argv[1].isString() )
        {
            arg1 = convertToStringW(argv[1].getString());

        }
        else if (!argv[1].isNull())
        {
            oRes.setArgError(L"Type error: argument " L"1" L" should be " L"string" );
            return oRes.toJSON();
        }
    }











        



    nCallbackArg = 3;

    






    bool arg2;
    if ( argc > 2 )
    {
        if ( argv[2].isString() )
            arg2 = argv[2].getInt() ? true : false;
        else if (!argv[2].isNull())
        {
            oRes.setArgError(L"Type error: argument " L"2" L" should be " L"boolean" );
            return oRes.toJSON();
        }
    }







        




    if ( argc > nCallbackArg )
    {

        oRes.setArgError(L"Wrong number of arguments: " + convertToStringW(argc) + L" instead of " + convertToStringW(3) );
        return oRes.toJSON();

        
        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError(L"Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError(L"Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }
        
    }


    pFunctor = rho_makeInstanceClassFunctor4( rho::system::CProcessFactoryBase::getProcessSingletonS(), &rho::system::IProcessSingleton::runApplication, arg0, arg1, arg2,  oRes );




    if ( bUseCallback )
        rho::system::CProcessFactoryBase::getProcessSingletonS()->addCommandToQueue( pFunctor );
    else
    {
        delete pFunctor;


        rho::system::CProcessFactoryBase::getProcessSingletonS()->runApplication( arg0, arg1, arg2,  oRes );


    }


    return oRes.toJSON();

}


rho::String js_Process_waitForApplication(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::IRhoRunnable* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;

    rho::system::IProcess* pObj = rho::system::CProcessFactoryBase::getInstance()->getModuleByID(convertToStringW(strObjID));




    if ( argc > nCallbackArg )
    {

        oRes.setArgError(L"Wrong number of arguments: " + convertToStringW(argc) + L" instead of " + convertToStringW(0) );
        return oRes.toJSON();

        
        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError(L"Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError(L"Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }
        
    }


    pFunctor = rho_makeInstanceClassFunctor1( pObj, &rho::system::IProcess::waitForApplication,  oRes );




    if ( bUseCallback )
        rho::system::CProcessFactoryBase::getProcessSingletonS()->addCommandToQueue( pFunctor );
    else
    {
        delete pFunctor;


        pObj->waitForApplication(  oRes );


    }


    return oRes.toJSON();

}


rho::String js_Process_closeHandle(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::IRhoRunnable* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;

    rho::system::IProcess* pObj = rho::system::CProcessFactoryBase::getInstance()->getModuleByID(convertToStringW(strObjID));




    if ( argc > nCallbackArg )
    {

        oRes.setArgError(L"Wrong number of arguments: " + convertToStringW(argc) + L" instead of " + convertToStringW(0) );
        return oRes.toJSON();

        
        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError(L"Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError(L"Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }
        
    }


    pFunctor = rho_makeInstanceClassFunctor1( pObj, &rho::system::IProcess::closeHandle,  oRes );




    if ( bUseCallback )
        rho::system::CProcessFactoryBase::getProcessSingletonS()->addCommandToQueue( pFunctor );
    else
    {
        delete pFunctor;


        pObj->closeHandle(  oRes );


    }


    return oRes.toJSON();

}


rho::String js_Process_getProcessExitCode(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::IRhoRunnable* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;

    rho::system::IProcess* pObj = rho::system::CProcessFactoryBase::getInstance()->getModuleByID(convertToStringW(strObjID));




    if ( argc > nCallbackArg )
    {

        oRes.setArgError(L"Wrong number of arguments: " + convertToStringW(argc) + L" instead of " + convertToStringW(0) );
        return oRes.toJSON();

        
        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError(L"Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError(L"Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }
        
    }


    pFunctor = rho_makeInstanceClassFunctor1( pObj, &rho::system::IProcess::getProcessExitCode,  oRes );




    if ( bUseCallback )
        rho::system::CProcessFactoryBase::getProcessSingletonS()->addCommandToQueue( pFunctor );
    else
    {
        delete pFunctor;


        pObj->getProcessExitCode(  oRes );


    }


    return oRes.toJSON();

}



