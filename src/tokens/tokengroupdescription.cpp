// Copyright (c) 2019 The ION Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "tokens/tokengroupdescription.h"
#include "util.h"
#include <univalue.h>

void CTokenGroupDescriptionBase::ToJson(UniValue& obj) const
{
    obj.clear();
    obj.setObject();
    obj.pushKV("ticker", strTicker);
    obj.pushKV("name", strName);
    obj.pushKV("document_URL", strDocumentUrl);
    obj.pushKV("documentHash", documentHash.ToString());
}

void CTokenGroupDescriptionRegular::ToJson(UniValue& obj) const
{
    CTokenGroupDescriptionBase::ToJson(obj);
    obj.pushKV("decimal_pos", (int)nDecimalPos);
}

void CTokenGroupDescriptionMGT::ToJson(UniValue& obj) const
{
    CTokenGroupDescriptionBase::ToJson(obj);
    obj.pushKV("decimal_pos", (int)nDecimalPos);
    obj.pushKV("bls_pubkey", blsPubKey.ToString());
}
