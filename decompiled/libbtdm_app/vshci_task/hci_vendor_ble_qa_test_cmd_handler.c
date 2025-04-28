/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> vshci_task.o -> hci_vendor_ble_qa_test_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_vendor_ble_qa_test_cmd_handler(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  ushort *puVar3;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(char *)(iVar1 + 0x17) == '\x01') {
    puVar3 = &ble_ext_funcs_list;
    iVar1 = 0;
    do {
      if (*puVar3 == (ushort)*param_1) {
        if ((code *)(&PTR_hci_vs_ble_qa_test_en_cmd_handler_00011334)[iVar1 * 2] != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000100a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar2 = (*(code *)(&PTR_hci_vs_ble_qa_test_en_cmd_handler_00011334)[iVar1 * 2])
                            (param_1 + 1);
          return uVar2;
        }
        break;
      }
      iVar1 = iVar1 + 1;
      puVar3 = puVar3 + 4;
    } while (iVar1 != 0x24);
  }
  (**(code **)(_r_ip_funcs_p + 0x4b8))(0xfd13,1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

