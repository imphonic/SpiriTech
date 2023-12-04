/*******************************************************
 * Copyright Rapidfire Computer Entertainment.        *
 * Licensed under GNU LGPL - see LICENSE for details. *
 * @file: application.hpp                              *
 * @brief: Implements the Application layer.           *
 * @author: Will Pimentel-Tonche                       *
*******************************************************/

namespace Para
  {
    /* Maintains info about the current application. */
    class App
      {
      public:
        static const char* GetRenderAPI()
          {
            return RenderAPI;
          }

        static void AssignRenderAPI(const char* in_api)
          {
            RenderAPI = in_api;
          }

      private:
        static const char* RenderAPI;
      };
  }