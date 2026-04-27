/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> llc_encrypt.o -> f_llc_encrypt_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_llc_encrypt_ind_handler(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  void *pvVar5;
  size_t sVar6;
  code *pcVar7;
  
  param_2 = param_2 >> 8;
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(byte *)(iVar1 + 0xd) <= param_2) {
    return 0;
  }
  iVar1 = *(int *)(&llc_env + param_2 * 4);
  if (iVar1 == 0) {
    return 0;
  }
  if ((*(byte *)(iVar1 + 0x44) & 3) == 3) {
    return 0;
  }
  if ((*(ushort *)(iVar1 + 0x42) & 1) != 0) {
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(param_2,0,*(code **)(_r_ip_funcs_p + 0x678));
    if (iVar2 == 3) {
      iVar1 = (**(code **)(_r_ip_funcs_p + 0x674))(param_2,0,*(code **)(_r_ip_funcs_p + 0x674));
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
      if (iVar2 == 3) {
        memcpy((void *)(iVar1 + 0x20),(void *)(param_1 + 1),4);
        sVar6 = 8;
        pvVar5 = (void *)(param_1 + 5);
        pvVar4 = (void *)(iVar1 + 0x28);
_L281:
        memcpy(pvVar4,pvVar5,sVar6);
      }
      else {
        if (iVar2 == 6) {
          sVar6 = 0x10;
          pvVar5 = (void *)(param_1 + 1);
          pvVar4 = (void *)(iVar1 + 0x10);
          goto _L281;
        }
        pcVar7 = *(code **)(_r_plf_funcs_p + 0xc);
        uVar3 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar1,*(code **)(_r_ip_funcs_p + 0x680));
        (*pcVar7)(param_2,uVar3,"llc_encrypt.c",0x8c4);
      }
      pcVar7 = *(code **)(_r_ip_funcs_p + 0x594);
      goto _L283;
    }
    if ((*(ushort *)(iVar1 + 0x42) & 1) != 0) {
      return 0;
    }
  }
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(param_2,1,*(code **)(_r_ip_funcs_p + 0x678));
  if (iVar1 != 3) {
    return 0;
  }
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x674))(param_2,1,*(code **)(_r_ip_funcs_p + 0x674));
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
  if (iVar2 == 0xd) {
    memcpy((void *)(iVar1 + 0x24),(void *)(param_1 + 1),4);
    sVar6 = 8;
    pvVar5 = (void *)(param_1 + 5);
    pvVar4 = (void *)(iVar1 + 0x30);
_L282:
    memcpy(pvVar4,pvVar5,sVar6);
  }
  else {
    if (iVar2 == 0xf) {
      sVar6 = 0x10;
      pvVar5 = (void *)(param_1 + 1);
      pvVar4 = (void *)(iVar1 + 0x10);
      goto _L282;
    }
    pcVar7 = *(code **)(_r_plf_funcs_p + 0xc);
    uVar3 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar1,*(code **)(_r_ip_funcs_p + 0x680));
    (*pcVar7)(param_2,uVar3,"llc_encrypt.c",0x8df);
  }
  pcVar7 = *(code **)(_r_ip_funcs_p + 0x59c);
_L283:
  uVar3 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar1,*(code **)(_r_ip_funcs_p + 0x680));
  (*pcVar7)(param_2,uVar3,0);
  return 0;
}

