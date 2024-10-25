/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
      if ((code *)(&PTR_hci_vs_ble_qa_test_en_cmd_handler_00010f88)[iVar2 * 2] == (code *)0x0) {
        return 0;
      }
                    /* WARNING: Could not recover jumptable at 0x00010e58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*(code *)(&PTR_hci_vs_ble_qa_test_en_cmd_handler_00010f88)[iVar2 * 2])
                        (param_1 + 1,param_2,param_3);
      return uVar1;
    }
    iVar2 = iVar2 + 1;
    puVar3 = puVar3 + 4;
  } while (iVar2 != 0x20);
  return 0;
}

