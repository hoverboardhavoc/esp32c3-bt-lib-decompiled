/*
 * Last changed at upstream commit eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * https://github.com/espressif/esp32c3-bt-lib/commit/eeb2782618e0ab8cf0cf609c98c6a0c86d691a6c
 * Upstream date: 2024-10-20 16:32:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(52ee788)
 * Source: libbtdm_app -> vshci_task.o -> hci_vendor_ble_qa_test_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_vendor_ble_qa_test_cmd_handler(byte *param_1)

{
  undefined4 uVar1;
  int iVar2;
  ushort *puVar3;
  
  puVar3 = &_LANCHOR0;
  iVar2 = 0;
  do {
    if (*puVar3 == (ushort)*param_1) {
      if ((code *)(&PTR_hci_vs_ble_qa_test_en_cmd_handler_00010f2c)[iVar2 * 2] == (code *)0x0) {
        return 0;
      }
                    /* WARNING: Could not recover jumptable at 0x000102ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*(code *)(&PTR_hci_vs_ble_qa_test_en_cmd_handler_00010f2c)[iVar2 * 2])(param_1 + 1);
      return uVar1;
    }
    iVar2 = iVar2 + 1;
    puVar3 = puVar3 + 4;
  } while (iVar2 != 0x20);
  return 0;
}

