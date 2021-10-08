/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// THIS FILE IS GENERATED BY ZAP

#include <cinttypes>
#include <cstdint>

#include "app/util/util.h"
#include <app-common/zap-generated/af-structs.h>
#include <app-common/zap-generated/callback.h>
#include <app-common/zap-generated/cluster-objects.h>
#include <app-common/zap-generated/ids/Clusters.h>
#include <app-common/zap-generated/ids/Commands.h>
#include <app/InteractionModelEngine.h>
#include <lib/core/CHIPSafeCasts.h>
#include <lib/support/TypeTraits.h>

// Currently we need some work to keep compatible with ember lib.
#include <app/util/ember-compatibility-functions.h>

namespace chip {
namespace app {

namespace {
void ReportCommandUnsupported(Command * aCommandObj, const ConcreteCommandPath & aCommandPath)
{
    aCommandObj->AddStatusCode(aCommandPath, Protocols::SecureChannel::GeneralStatusCode::kNotFound, Protocols::SecureChannel::Id,
                               Protocols::InteractionModel::Status::UnsupportedCommand);
    ChipLogError(Zcl, "Unknown command " ChipLogFormatMEI " for cluster " ChipLogFormatMEI,
                 ChipLogValueMEI(aCommandPath.mCommandId), ChipLogValueMEI(aCommandPath.mClusterId));
}
} // anonymous namespace

// Cluster specific command parsing

namespace Clusters {

namespace OtaSoftwareUpdateProvider {

void DispatchServerCommand(CommandHandler * apCommandObj, const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aDataTlv)
{
    // We are using TLVUnpackError and TLVError here since both of them can be CHIP_END_OF_TLV
    // When TLVError is CHIP_END_OF_TLV, it means we have iterated all of the items, which is not a real error.
    // Any error value TLVUnpackError means we have received an illegal value.
    // The following variables are used for all commands to save code size.
    CHIP_ERROR TLVError = CHIP_NO_ERROR;
    bool wasHandled     = false;
    {
        switch (aCommandPath.mCommandId)
        {
        case Commands::ApplyUpdateRequest::Id: {
            Commands::ApplyUpdateRequest::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfOtaSoftwareUpdateProviderClusterApplyUpdateRequestCallback(
                    apCommandObj, aCommandPath, aCommandPath.mEndpointId, commandData.updateToken, commandData.newVersion,
                    commandData);
            }
            break;
        }
        case Commands::NotifyUpdateApplied::Id: {
            Commands::NotifyUpdateApplied::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfOtaSoftwareUpdateProviderClusterNotifyUpdateAppliedCallback(
                    apCommandObj, aCommandPath, aCommandPath.mEndpointId, commandData.updateToken, commandData.softwareVersion,
                    commandData);
            }
            break;
        }
        case Commands::QueryImage::Id: {
            Commands::QueryImage::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfOtaSoftwareUpdateProviderClusterQueryImageCallback(
                    apCommandObj, aCommandPath, aCommandPath.mEndpointId, commandData.vendorId, commandData.productId,
                    commandData.hardwareVersion, commandData.softwareVersion, to_underlying(commandData.protocolsSupported),
                    const_cast<uint8_t *>(Uint8::from_const_char(commandData.location.data())), commandData.requestorCanConsent,
                    commandData.metadataForProvider, commandData);
            }
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            ReportCommandUnsupported(apCommandObj, aCommandPath);
            return;
        }
        }
    }

    if (CHIP_NO_ERROR != TLVError || !wasHandled)
    {
        apCommandObj->AddStatusCode(aCommandPath, Protocols::SecureChannel::GeneralStatusCode::kBadRequest,
                                    Protocols::SecureChannel::Id, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogProgress(Zcl, "Failed to dispatch command, TLVError=%" CHIP_ERROR_FORMAT, TLVError.Format());
    }
}

} // namespace OtaSoftwareUpdateProvider

namespace OperationalCredentials {

void DispatchServerCommand(CommandHandler * apCommandObj, const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aDataTlv)
{
    // We are using TLVUnpackError and TLVError here since both of them can be CHIP_END_OF_TLV
    // When TLVError is CHIP_END_OF_TLV, it means we have iterated all of the items, which is not a real error.
    // Any error value TLVUnpackError means we have received an illegal value.
    // The following variables are used for all commands to save code size.
    CHIP_ERROR TLVError = CHIP_NO_ERROR;
    bool wasHandled     = false;
    {
        switch (aCommandPath.mCommandId)
        {
        case Commands::AddNOC::Id: {
            Commands::AddNOC::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfOperationalCredentialsClusterAddNOCCallback(
                    apCommandObj, aCommandPath, aCommandPath.mEndpointId, commandData.NOCValue, commandData.ICACValue,
                    commandData.IPKValue, commandData.caseAdminNode, commandData.adminVendorId, commandData);
            }
            break;
        }
        case Commands::AddTrustedRootCertificate::Id: {
            Commands::AddTrustedRootCertificate::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfOperationalCredentialsClusterAddTrustedRootCertificateCallback(
                    apCommandObj, aCommandPath, aCommandPath.mEndpointId, commandData.rootCertificate, commandData);
            }
            break;
        }
        case Commands::AttestationRequest::Id: {
            Commands::AttestationRequest::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfOperationalCredentialsClusterAttestationRequestCallback(
                    apCommandObj, aCommandPath, aCommandPath.mEndpointId, commandData.attestationNonce, commandData);
            }
            break;
        }
        case Commands::CertificateChainRequest::Id: {
            Commands::CertificateChainRequest::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfOperationalCredentialsClusterCertificateChainRequestCallback(
                    apCommandObj, aCommandPath, aCommandPath.mEndpointId, commandData.certificateType, commandData);
            }
            break;
        }
        case Commands::OpCSRRequest::Id: {
            Commands::OpCSRRequest::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfOperationalCredentialsClusterOpCSRRequestCallback(
                    apCommandObj, aCommandPath, aCommandPath.mEndpointId, commandData.CSRNonce, commandData);
            }
            break;
        }
        case Commands::RemoveFabric::Id: {
            Commands::RemoveFabric::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfOperationalCredentialsClusterRemoveFabricCallback(
                    apCommandObj, aCommandPath, aCommandPath.mEndpointId, commandData.fabricIndex, commandData);
            }
            break;
        }
        case Commands::UpdateFabricLabel::Id: {
            Commands::UpdateFabricLabel::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfOperationalCredentialsClusterUpdateFabricLabelCallback(
                    apCommandObj, aCommandPath, aCommandPath.mEndpointId,
                    const_cast<uint8_t *>(Uint8::from_const_char(commandData.label.data())), commandData);
            }
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            ReportCommandUnsupported(apCommandObj, aCommandPath);
            return;
        }
        }
    }

    if (CHIP_NO_ERROR != TLVError || !wasHandled)
    {
        apCommandObj->AddStatusCode(aCommandPath, Protocols::SecureChannel::GeneralStatusCode::kBadRequest,
                                    Protocols::SecureChannel::Id, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogProgress(Zcl, "Failed to dispatch command, TLVError=%" CHIP_ERROR_FORMAT, TLVError.Format());
    }
}

} // namespace OperationalCredentials

} // namespace Clusters

void DispatchSingleClusterCommand(const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aReader, CommandHandler * apCommandObj)
{
    ChipLogDetail(Zcl, "Received Cluster Command: Endpoint=%" PRIx16 " Cluster=" ChipLogFormatMEI " Command=" ChipLogFormatMEI,
                  aCommandPath.mEndpointId, ChipLogValueMEI(aCommandPath.mClusterId), ChipLogValueMEI(aCommandPath.mCommandId));

    Compatibility::SetupEmberAfObjects(apCommandObj, aCommandPath);

    switch (aCommandPath.mClusterId)
    {
    case Clusters::OtaSoftwareUpdateProvider::Id:
        Clusters::OtaSoftwareUpdateProvider::DispatchServerCommand(apCommandObj, aCommandPath, aReader);
        break;
    case Clusters::OperationalCredentials::Id:
        Clusters::OperationalCredentials::DispatchServerCommand(apCommandObj, aCommandPath, aReader);
        break;
    default:
        ChipLogError(Zcl, "Unknown cluster " ChipLogFormatMEI, ChipLogValueMEI(aCommandPath.mClusterId));
        apCommandObj->AddStatusCode(aCommandPath, Protocols::SecureChannel::GeneralStatusCode::kNotFound,
                                    Protocols::InteractionModel::Id, Protocols::InteractionModel::Status::UnsupportedCluster);
        break;
    }

    Compatibility::ResetEmberAfObjects();
}

void DispatchSingleClusterResponseCommand(const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aReader,
                                          CommandSender * apCommandObj)
{
    ChipLogDetail(Zcl, "Received Cluster Command: Endpoint=%" PRIx16 " Cluster=" ChipLogFormatMEI " Command=" ChipLogFormatMEI,
                  aCommandPath.mEndpointId, ChipLogValueMEI(aCommandPath.mClusterId), ChipLogValueMEI(aCommandPath.mCommandId));

    Compatibility::SetupEmberAfObjects(apCommandObj, aCommandPath);

    TLV::TLVType dataTlvType;
    SuccessOrExit(aReader.EnterContainer(dataTlvType));
    switch (aCommandPath.mClusterId)
    {
    default:
        ChipLogError(Zcl, "Unknown cluster " ChipLogFormatMEI, ChipLogValueMEI(aCommandPath.mClusterId));
        apCommandObj->AddStatusCode(aCommandPath, Protocols::SecureChannel::GeneralStatusCode::kNotFound,
                                    Protocols::InteractionModel::Id, Protocols::InteractionModel::Status::UnsupportedCluster);
        break;
    }

exit:
    aReader.ExitContainer(dataTlvType);
    Compatibility::ResetEmberAfObjects();
}

} // namespace app
} // namespace chip
