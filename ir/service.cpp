/*
 * Copyright 2016 The Android Open Source Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_TAG "android.hardware.ir@1.0-service.jasmine_sprout"

#include <android-base/logging.h>
#include <hidl/HidlTransportSupport.h>
#include "ConsumerIr.h"

using android::hardware::ir::V1_0::IConsumerIr;
using android::hardware::ir::V1_0::implementation::ConsumerIr;
using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;

int main() {
    android::sp<IConsumerIr> service = new ConsumerIr();

    configureRpcThreadpool(1, true /*callerWillJoin*/);

    android::status_t status = service->registerAsService();
    if (status != android::OK) {
        LOG(ERROR) << "Cannot register ConsumerIr service";
        return 1;
    }

    joinRpcThreadpool();

    return 1; // should never get here
}
