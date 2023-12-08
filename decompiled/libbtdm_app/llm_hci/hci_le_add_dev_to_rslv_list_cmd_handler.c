/*
 * Last changed at upstream commit bb9f0f59db474924c9288ab92aed1abb88bc9419
 * https://github.com/espressif/esp32c3-bt-lib/commit/bb9f0f59db474924c9288ab92aed1abb88bc9419
 * Upstream date: 2023-12-08 13:35:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(65db61f)
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
  uint uVar4;
  int iVar5;
  int iVar6;
  byte *__s1;
  
  iVar5 = 0x12;
  if (*param_1 < 2) {
    if (*(char *)(_p_llm_env + 0xc6) != '\0') {
      iVar5 = 0xc;
      iVar1 = (**(code **)(_r_ip_funcs_p + 0x504))(*(code **)(_r_ip_funcs_p + 0x504));
      if (iVar1 != 0) goto _L181;
    }
    __s1 = param_1 + 1;
    for (iVar5 = 0; iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
        iVar5 < (int)(uint)*(byte *)(iVar1 + 0xd); iVar5 = iVar5 + 1) {
      iVar6 = iVar5 * 0x44 + *(int *)(_p_llm_env + 8);
      iVar1 = memcmp(__s1,(void *)(iVar6 + 4),6);
      if ((iVar1 == 0) && (*(char *)(iVar6 + 0x40) == '\t')) {
        uVar3 = 1;
        goto _L186;
      }
    }
    uVar3 = 0;
_L186:
    uVar2 = (**(code **)(_r_ip_funcs_p + 0x4c8))(__s1,*param_1,*(code **)(_r_ip_funcs_p + 0x4c8));
    uVar4 = 0;
    if (uVar2 < 0xc) {
      uVar4 = (int)(uint)*(byte *)(uVar2 * 10 + _p_llm_env + 0x2d) >> 1 & 1;
    }
    iVar5 = (**(code **)(_r_ip_funcs_p + 0x274))
                      (__s1,param_1 + 7,param_1 + 0x17,*param_1,uVar3,uVar4,
                       *(code **)(_r_ip_funcs_p + 0x274));
    if ((iVar5 == 0) && (iVar1 = lld_ral_valid_count(), iVar1 == 1)) {
      (**(code **)(_r_modules_funcs_p + 0xc4))
                (6,0,(uint)*(ushort *)(_p_llm_env + 0xc4) * 100,
                 *(code **)(_r_modules_funcs_p + 0xc4));
      (**(code **)(_r_ip_funcs_p + 0x294))(*(code **)(_r_ip_funcs_p + 0x294));
    }
  }
_L181:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar5,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

