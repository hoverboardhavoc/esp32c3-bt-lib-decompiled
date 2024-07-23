/*
 * Last changed at upstream commit d4922c5890feb6ee1733e6063369ff54a30f5930
 * https://github.com/espressif/esp32c3-bt-lib/commit/d4922c5890feb6ee1733e6063369ff54a30f5930
 * Upstream date: 2024-07-23 16:16:25 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(4e58df9)
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
      if ((code *)(&PTR_hci_vs_ble_qa_test_en_cmd_handler_00010ce0)[iVar2 * 2] == (code *)0x0) {
        return 0;
      }
                    /* WARNING: Could not recover jumptable at 0x000102e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*(code *)(&PTR_hci_vs_ble_qa_test_en_cmd_handler_00010ce0)[iVar2 * 2])(param_1 + 1);
      return uVar1;
    }
    iVar2 = iVar2 + 1;
    puVar3 = puVar3 + 4;
  } while (iVar2 != 0x1d);
  return 0;
}

