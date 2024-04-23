/*
 * Last changed at upstream commit 9780fd66d97866977d972fb63319830f47f12785
 * https://github.com/espressif/esp32c3-bt-lib/commit/9780fd66d97866977d972fb63319830f47f12785
 * Upstream date: 2024-04-23 11:19:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a771b7c)
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
  int iVar4;
  char local_29;
  undefined1 auStack_28 [20];
  
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x508))(*(code **)(_r_ip_funcs_p + 0x508));
  uVar3 = 0xc;
  if (iVar1 == 0) goto _L200;
  if ((byte)(*param_1 - 2U) < 0xfd) {
_L197:
    uVar3 = 0x12;
  }
  else {
    local_29 = *param_1;
    memcpy(auStack_28,param_1 + 1,6);
    lld_wl_rpa_res(auStack_28,&local_29,1);
    uVar2 = (**(code **)(_r_ip_funcs_p + 0x4c8))
                      (auStack_28,local_29,*(code **)(_r_ip_funcs_p + 0x4c8));
    if (uVar2 < 0xc) {
      if ((*(byte *)(_p_llm_env + uVar2 * 10 + 0x2d) & 2) != 0) goto _L197;
    }
    else {
      uVar2 = (**(code **)(_r_ip_funcs_p + 0x4c4))(*(code **)(_r_ip_funcs_p + 0x4c4));
      uVar3 = 7;
      if (uVar2 == 0xc) goto _L200;
    }
    iVar4 = _p_llm_env + uVar2 * 10;
    memcpy((void *)(iVar4 + 0x24),auStack_28,6);
    *(byte *)(iVar4 + 0x2d) = *(byte *)(iVar4 + 0x2d) | 3;
    iVar1 = _r_ip_funcs_p;
    *(char *)(iVar4 + 0x2c) = local_29;
    iVar1 = (**(code **)(iVar1 + 0x4d8))(auStack_28,*(code **)(iVar1 + 0x4d8));
    if (iVar1 == 0) {
      (**(code **)(_r_ip_funcs_p + 700))(uVar2,auStack_28,local_29,*(code **)(_r_ip_funcs_p + 700));
    }
    uVar3 = 0;
  }
_L200:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar3,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

