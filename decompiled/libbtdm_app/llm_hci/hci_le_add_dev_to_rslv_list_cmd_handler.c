/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_add_dev_to_rslv_list_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_add_dev_to_rslv_list_cmd_handler(byte *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 extraout_a1;
  uint uVar5;
  int iVar6;
  byte *__s1;
  int iVar7;
  
  uVar3 = 0x12;
  if (*param_1 < 2) {
    uVar4 = uVar3;
    if (*(char *)(_p_llm_env + 0xc6) != '\0') {
      iVar6 = (**(code **)(_r_ip_funcs_p + 0x504))(0x12,*(code **)(_r_ip_funcs_p + 0x504));
      uVar4 = 0xc;
      uVar3 = 0xc;
      if (iVar6 != 0) goto _L100;
    }
    __s1 = param_1 + 1;
    for (iVar6 = 0;
        iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(uVar4,*(code **)(_r_plf_funcs_p + 0x38)),
        iVar6 < (int)(uint)*(byte *)(iVar1 + 0xd); iVar6 = iVar6 + 1) {
      iVar7 = iVar6 * 0x44 + *(int *)(_p_llm_env + 8);
      iVar1 = memcmp(__s1,(void *)(iVar7 + 4),6);
      if ((iVar1 == 0) && (*(char *)(iVar7 + 0x40) == '\t')) {
        uVar3 = 1;
        goto _L105;
      }
      uVar4 = extraout_a1;
    }
    uVar3 = 0;
_L105:
    uVar2 = (**(code **)(_r_ip_funcs_p + 0x4c8))(__s1,*param_1,*(code **)(_r_ip_funcs_p + 0x4c8));
    uVar5 = 0;
    if (uVar2 < 0xc) {
      uVar5 = (int)(uint)*(byte *)(uVar2 * 10 + _p_llm_env + 0x2d) >> 1 & 1;
    }
    uVar3 = (**(code **)(_r_ip_funcs_p + 0x274))
                      (__s1,param_1 + 7,param_1 + 0x17,*param_1,uVar3,uVar5,
                       *(code **)(_r_ip_funcs_p + 0x274));
  }
_L100:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar3,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

