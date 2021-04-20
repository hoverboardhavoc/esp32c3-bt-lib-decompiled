/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_add_dev_to_wlst_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_add_dev_to_wlst_cmd_handler(char *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  char *__src;
  
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x508))(*(code **)(_r_ip_funcs_p + 0x508));
  uVar3 = 0xc;
  if (iVar1 == 0) goto _L163;
  if ((byte)(*param_1 - 2U) < 0xfd) {
_L166:
    uVar3 = 0x12;
  }
  else {
    __src = param_1 + 1;
    uVar2 = (**(code **)(_r_ip_funcs_p + 0x4c8))(__src,*(code **)(_r_ip_funcs_p + 0x4c8));
    if (uVar2 < 0xc) {
      if ((*(byte *)(_p_llm_env + uVar2 * 10 + 0x2d) & 2) != 0) goto _L166;
    }
    else {
      uVar3 = 7;
      uVar2 = (**(code **)(_r_ip_funcs_p + 0x4c4))(*(code **)(_r_ip_funcs_p + 0x4c4));
      if (uVar2 == 0xc) goto _L163;
    }
    memcpy((void *)(_p_llm_env + uVar2 * 10 + 0x24),__src,6);
    iVar1 = _p_llm_env + uVar2 * 10;
    *(char *)(iVar1 + 0x2c) = *param_1;
    *(byte *)(iVar1 + 0x2d) = *(byte *)(iVar1 + 0x2d) | 3;
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x4d8))(__src,*(code **)(_r_ip_funcs_p + 0x4d8));
    uVar3 = 0;
    if (iVar1 == 0) {
      (**(code **)(_r_ip_funcs_p + 700))(uVar2,__src,*param_1,*(code **)(_r_ip_funcs_p + 700));
      uVar3 = 0;
    }
  }
_L163:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar3,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

