/*===================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center,
Division of Medical and Biological Informatics.
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/

#ifndef MITKRESTCLIENT_H
#define MITKRESTCLIENT_H

#include "cpprest/asyncrt_utils.h"
#include "cpprest/containerstream.h"
#include "cpprest/filestream.h"
#include "cpprest/http_client.h"
#include "cpprest/json.h"
#include "cpprest/producerconsumerstream.h"
#include "cpprest/uri.h"

// hm.. maybe go after that warning at some time? seems like a nasty hack, but works so far :)
#pragma warning(disable : 4251)

#include "MitkCppRestSdkExports.h"

typedef web::http::client::http_client MitkClient;
typedef web::http::http_request MitkRequest;
typedef web::http::http_response MitkResponse;
typedef web::http::methods MitkRESTMethods;
typedef web::http::uri_builder MitkUriBuilder;
typedef web::http::status_codes MitkRestStatusCodes;
typedef web::json::json_exception MitkJsonException;

namespace mitk
{
  class MITKCPPRESTSDK_EXPORT RESTClient
  {
  public:;
    RESTClient(utility::string_t url);
    virtual ~RESTClient();

    void executeGETRequest(utility::string_t uri);
    void executeWADOGET(std::string studyUID, std::string seriesUID, std::string instanceUID);
 
  private:
    MitkClient m_Client;

  };
};

#endif // MITKRESTCLIENT_H