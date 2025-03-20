/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app -> llc_encrypt.o -> llc_encrypt_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llc_encrypt_ind_handler(undefined4 param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  void *pvVar5;
  size_t sVar6;
  code *pcVar7;
  
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar4 + 0x20) == '\0') {
    return 0;
  }
  param_3 = param_3 >> 8;
  iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(param_1,param_4,*(code **)(_r_plf_funcs_p + 0x38));
  if (*(byte *)(iVar4 + 0xd) <= param_3) {
    return 0;
  }
  iVar4 = *(int *)(&llc_env + param_3 * 4);
  if (iVar4 == 0) {
    return 0;
  }
  if ((*(byte *)(iVar4 + 0x44) & 3) == 3) {
    return 0;
  }
  if ((*(ushort *)(iVar4 + 0x42) & 1) != 0) {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(param_3,0,*(code **)(_r_ip_funcs_p + 0x678));
    if (iVar1 == 3) {
      iVar4 = (**(code **)(_r_ip_funcs_p + 0x674))(param_3,0,*(code **)(_r_ip_funcs_p + 0x674));
      iVar1 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
      if (iVar1 == 3) {
        memcpy((void *)(iVar4 + 0x20),(void *)(param_2 + 1),4);
        sVar6 = 8;
        pvVar5 = (void *)(param_2 + 5);
        pvVar3 = (void *)(iVar4 + 0x28);
_L269:
        memcpy(pvVar3,pvVar5,sVar6);
      }
      else {
        if (iVar1 == 6) {
          sVar6 = 0x10;
          pvVar5 = (void *)(param_2 + 1);
          pvVar3 = (void *)(iVar4 + 0x10);
          goto _L269;
        }
        pcVar7 = *(code **)(_r_plf_funcs_p + 0xc);
        uVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar4,*(code **)(_r_ip_funcs_p + 0x680));
        (*pcVar7)(param_3,uVar2,"llc_encrypt.c",0x884);
      }
      pcVar7 = *(code **)(_r_ip_funcs_p + 0x594);
      goto _L271;
    }
    if ((*(ushort *)(iVar4 + 0x42) & 1) != 0) {
      return 0;
    }
  }
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x678))(param_3,1,*(code **)(_r_ip_funcs_p + 0x678));
  if (iVar4 != 3) {
    return 0;
  }
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x674))(param_3,1,*(code **)(_r_ip_funcs_p + 0x674));
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
  if (iVar1 == 0xd) {
    memcpy((void *)(iVar4 + 0x24),(void *)(param_2 + 1),4);
    sVar6 = 8;
    pvVar5 = (void *)(param_2 + 5);
    pvVar3 = (void *)(iVar4 + 0x30);
_L270:
    memcpy(pvVar3,pvVar5,sVar6);
  }
  else {
    if (iVar1 == 0xf) {
      sVar6 = 0x10;
      pvVar5 = (void *)(param_2 + 1);
      pvVar3 = (void *)(iVar4 + 0x10);
      goto _L270;
    }
    pcVar7 = *(code **)(_r_plf_funcs_p + 0xc);
    uVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar4,*(code **)(_r_ip_funcs_p + 0x680));
    (*pcVar7)(param_3,uVar2,"llc_encrypt.c",0x89f);
  }
  pcVar7 = *(code **)(_r_ip_funcs_p + 0x59c);
_L271:
  uVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar4,*(code **)(_r_ip_funcs_p + 0x680));
  (*pcVar7)(param_3,uVar2,0);
  return 0;
}

