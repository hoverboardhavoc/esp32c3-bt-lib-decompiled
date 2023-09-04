/*
 * Last changed at upstream commit 9e82ccc6cd24923b2e46e5b05064ccbbf1b2ac09
 * https://github.com/espressif/esp32c3-bt-lib/commit/9e82ccc6cd24923b2e46e5b05064ccbbf1b2ac09
 * Upstream date: 2023-09-04 20:35:54 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(3a1003fc)
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
    if (*(char *)(iVar4 + 4) == '\x01') {
      *(undefined1 *)(iVar2 + 8) = 1;
    }
    else {
      *(undefined1 *)(iVar2 + 8) = 0;
    }
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
                    /* WARNING: Could not recover jumptable at 0x0001054e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x2c))(iVar2);
  return;
}

