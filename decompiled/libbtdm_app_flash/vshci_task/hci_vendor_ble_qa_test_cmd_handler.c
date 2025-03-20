/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
  
  iVar1 = r_sdk_config_get_opts();
  if (*(char *)(iVar1 + 0x17) == '\x01') {
    puVar3 = &_LANCHOR1;
    iVar1 = 0;
    do {
      if (*puVar3 == (ushort)*param_1) {
        if ((code *)(&PTR_hci_vs_ble_qa_test_en_cmd_handler_00010fb0)[iVar1 * 2] != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000100fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar2 = (*(code *)(&PTR_hci_vs_ble_qa_test_en_cmd_handler_00010fb0)[iVar1 * 2])
                            (param_1 + 1,param_2,param_3);
          return uVar2;
        }
        break;
      }
      iVar1 = iVar1 + 1;
      puVar3 = puVar3 + 4;
    } while (iVar1 != 0x20);
  }
  r_llm_cmd_cmp_send(0xfd13,1);
  return 0;
}

