/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> f_llc_encrypt_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 f_llc_encrypt_ind_handler(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  void *pvVar5;
  size_t sVar6;
  
  param_2 = param_2 >> 8;
  iVar1 = r_sdk_config_get_opts();
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
    iVar2 = r_llc_proc_id_get(param_2,0);
    if (iVar2 == 3) {
      iVar1 = r_llc_proc_get(param_2,0);
      iVar2 = r_llc_proc_state_get();
      if (iVar2 == 3) {
        memcpy((void *)(iVar1 + 0x20),(void *)(param_1 + 1),4);
        sVar6 = 8;
        pvVar5 = (void *)(param_1 + 5);
        pvVar4 = (void *)(iVar1 + 0x28);
      }
      else {
        if (iVar2 != 6) {
          uVar3 = r_llc_proc_state_get(iVar1);
          r_assert_param(param_2,uVar3,"llc_encrypt.c",0x8a5);
          goto _L261;
        }
        sVar6 = 0x10;
        pvVar5 = (void *)(param_1 + 1);
        pvVar4 = (void *)(iVar1 + 0x10);
      }
      memcpy(pvVar4,pvVar5,sVar6);
_L261:
      uVar3 = r_llc_proc_state_get(iVar1);
      r_llc_loc_encrypt_proc_continue(param_2,uVar3,0);
      return 0;
    }
    if ((*(ushort *)(iVar1 + 0x42) & 1) != 0) {
      return 0;
    }
  }
  iVar1 = r_llc_proc_id_get(param_2,1);
  if (iVar1 != 3) {
    return 0;
  }
  iVar1 = r_llc_proc_get(param_2,1);
  iVar2 = r_llc_proc_state_get();
  if (iVar2 == 0xd) {
    memcpy((void *)(iVar1 + 0x24),(void *)(param_1 + 1),4);
    sVar6 = 8;
    pvVar5 = (void *)(param_1 + 5);
    pvVar4 = (void *)(iVar1 + 0x30);
  }
  else {
    if (iVar2 != 0xf) {
      uVar3 = r_llc_proc_state_get(iVar1);
      r_assert_param(param_2,uVar3,"llc_encrypt.c",0x8c0);
      goto _L266;
    }
    sVar6 = 0x10;
    pvVar5 = (void *)(param_1 + 1);
    pvVar4 = (void *)(iVar1 + 0x10);
  }
  memcpy(pvVar4,pvVar5,sVar6);
_L266:
  uVar3 = r_llc_proc_state_get(iVar1);
  r_llc_rem_encrypt_proc_continue_eco(param_2,uVar3,0);
  return 0;
}

