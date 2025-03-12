/*
 * Last changed at upstream commit b5ead6b6d5758629370c91897168b8bcdfdcc169
 * https://github.com/espressif/esp32c3-bt-lib/commit/b5ead6b6d5758629370c91897168b8bcdfdcc169
 * Upstream date: 2025-03-12 20:14:26 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(9f6be86f)
 * Source: libbtdm_app_flash -> vshci_task.o -> hci_vendor_ble_qa_test_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_vendor_ble_qa_test_cmd_handler(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  ushort *puVar3;
  uint uVar4;
  
  if (DAT_00010fe4 != 0) {
    if (_LANCHOR0 != (ushort *)0x0) {
      iVar1 = r_sdk_config_get_opts();
      if (*(char *)(iVar1 + 0x17) == '\x01') {
        puVar3 = _LANCHOR0;
        for (uVar4 = 0; uVar4 < DAT_00010fe4; uVar4 = uVar4 + 1) {
          if (*puVar3 == (ushort)*param_1) {
            if (*(code **)(puVar3 + 2) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00010b0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              uVar2 = (**(code **)(puVar3 + 2))(param_1 + 1,param_2,param_3);
              return uVar2;
            }
            break;
          }
          puVar3 = puVar3 + 4;
        }
      }
    }
  }
  r_llm_cmd_cmp_send(0xfd13,1);
  return 0;
}

