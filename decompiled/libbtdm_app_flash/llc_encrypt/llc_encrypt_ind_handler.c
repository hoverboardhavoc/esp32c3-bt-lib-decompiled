/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> llc_encrypt_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 llc_encrypt_ind_handler(undefined4 param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  void *pvVar5;
  size_t sVar6;
  
  iVar4 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar4 + 0x20) == '\0') {
    return 0;
  }
  param_3 = param_3 >> 8;
  iVar4 = r_sdk_config_get_opts(param_1,param_4);
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
    iVar1 = r_llc_proc_id_get(param_3,0);
    if (iVar1 == 3) {
      iVar4 = r_llc_proc_get(param_3,0);
      iVar1 = r_llc_proc_state_get();
      if (iVar1 == 3) {
        memcpy((void *)(iVar4 + 0x20),(void *)(param_2 + 1),4);
        sVar6 = 8;
        pvVar5 = (void *)(param_2 + 5);
        pvVar3 = (void *)(iVar4 + 0x28);
      }
      else {
        if (iVar1 != 6) {
          uVar2 = r_llc_proc_state_get(iVar4);
          r_assert_param(param_3,uVar2,"llc_encrypt.c",0x8bf);
          goto _L272;
        }
        sVar6 = 0x10;
        pvVar5 = (void *)(param_2 + 1);
        pvVar3 = (void *)(iVar4 + 0x10);
      }
      memcpy(pvVar3,pvVar5,sVar6);
_L272:
      uVar2 = r_llc_proc_state_get(iVar4);
      r_llc_loc_encrypt_proc_continue(param_3,uVar2,0);
      return 0;
    }
    if ((*(ushort *)(iVar4 + 0x42) & 1) != 0) {
      return 0;
    }
  }
  iVar4 = r_llc_proc_id_get(param_3,1);
  if (iVar4 != 3) {
    return 0;
  }
  iVar4 = r_llc_proc_get(param_3,1);
  iVar1 = r_llc_proc_state_get();
  if (iVar1 == 0xd) {
    memcpy((void *)(iVar4 + 0x24),(void *)(param_2 + 1),4);
    sVar6 = 8;
    pvVar5 = (void *)(param_2 + 5);
    pvVar3 = (void *)(iVar4 + 0x30);
  }
  else {
    if (iVar1 != 0xf) {
      uVar2 = r_llc_proc_state_get(iVar4);
      r_assert_param(param_3,uVar2,"llc_encrypt.c",0x8da);
      goto _L277;
    }
    sVar6 = 0x10;
    pvVar5 = (void *)(param_2 + 1);
    pvVar3 = (void *)(iVar4 + 0x10);
  }
  memcpy(pvVar3,pvVar5,sVar6);
_L277:
  uVar2 = r_llc_proc_state_get(iVar4);
  r_llc_rem_encrypt_proc_continue_eco(param_3,uVar2,0);
  return 0;
}

