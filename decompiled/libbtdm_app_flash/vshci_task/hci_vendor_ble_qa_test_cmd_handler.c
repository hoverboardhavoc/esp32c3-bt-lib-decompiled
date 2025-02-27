/*
 * Last changed at upstream commit 0cfafa1e0aa30b7d59f53c38588f0598e228d127
 * https://github.com/espressif/esp32c3-bt-lib/commit/0cfafa1e0aa30b7d59f53c38588f0598e228d127
 * Upstream date: 2025-02-27 20:50:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b34b7d6)
 * Source: libbtdm_app_flash -> vshci_task.o -> hci_vendor_ble_qa_test_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_vendor_ble_qa_test_cmd_handler(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  ushort *puVar3;
  
  iVar2 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar2 + 0x21) == '\0') {
    return 0;
  }
  puVar3 = &_LANCHOR0;
  iVar2 = 0;
  do {
    if (*puVar3 == (ushort)*param_1) {
      if ((code *)(&PTR_hci_vs_ble_qa_test_en_cmd_handler_0001100c)[iVar2 * 2] == (code *)0x0) {
        return 0;
      }
                    /* WARNING: Could not recover jumptable at 0x00010edc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*(code *)(&PTR_hci_vs_ble_qa_test_en_cmd_handler_0001100c)[iVar2 * 2])
                        (param_1 + 1,param_2,param_3);
      return uVar1;
    }
    iVar2 = iVar2 + 1;
    puVar3 = puVar3 + 4;
  } while (iVar2 != 0x20);
  return 0;
}

