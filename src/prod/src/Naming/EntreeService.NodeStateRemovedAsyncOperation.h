// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------

#pragma once

namespace Naming
{
    class EntreeService::NodeStateRemovedAsyncOperation : public EntreeService::AdminRequestAsyncOperationBase
    {
    public:
        NodeStateRemovedAsyncOperation(
            __in GatewayProperties & properties,
            Transport::MessageUPtr && receivedMessage,
            Common::TimeSpan timeout,
            Common::AsyncCallback const & callback, 
            Common::AsyncOperationSPtr const & parent);

    protected:
        void OnStartRequest(Common::AsyncOperationSPtr const & thisSPtr) override;

    private:
        void StartRequest(Common::AsyncOperationSPtr const & thisSPtr);
        void OnRequestCompleted(
            Common::AsyncOperationSPtr const & asyncOperation, 
            bool expectedCompletedSynchronously);
        void OnRetry(Common::AsyncOperationSPtr const & thisSPtr);
        bool IsRetryable(Common::ErrorCode const& error);
    };
}
