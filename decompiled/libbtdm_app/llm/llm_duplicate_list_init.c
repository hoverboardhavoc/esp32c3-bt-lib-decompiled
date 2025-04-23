/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm.o -> llm_duplicate_list_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llm_duplicate_list_init(void)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x924))(*(code **)(_r_ip_funcs_p + 0x924));
  uVar3 = sdk_config_get_mask();
  if ((uVar3 & 1) != 0) {
    iVar4 = (**(code **)(_r_modules_funcs_p + 0x50))
                      (iVar2 + 0x10,*(code **)(_r_modules_funcs_p + 0x50));
    if (iVar4 != 0) {
      llm_util_flush_list(iVar2 + 0x10);
    }
    iVar4 = (**(code **)(_r_modules_funcs_p + 0x50))(iVar2,*(code **)(_r_modules_funcs_p + 0x50));
    if (iVar4 != 0) {
      llm_util_flush_list(iVar2);
    }
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    *(bool *)(iVar2 + 8) = *(char *)(iVar4 + 4) == '\x01';
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    *(undefined1 *)(iVar2 + 9) = *(undefined1 *)(iVar4 + 5);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    *(undefined2 *)(iVar2 + 10) = *(undefined2 *)(iVar4 + 6);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    uVar1 = *(undefined2 *)(iVar4 + 8);
    *(undefined4 *)(iVar2 + 0x18) = 0;
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    *(undefined2 *)(iVar2 + 0xc) = uVar1;
  }
  if (*(char *)(iVar2 + 8) != '\0') {
    (**(code **)(_r_modules_funcs_p + 0x2c))(iVar2 + 0x10,*(code **)(_r_modules_funcs_p + 0x2c));
  }
                    /* WARNING: Could not recover jumptable at 0x00010526. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x2c))(iVar2,*(code **)(_r_modules_funcs_p + 0x2c));
  return;
}

