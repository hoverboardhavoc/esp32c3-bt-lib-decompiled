/*
 * Last changed at upstream commit 2a91d90e33b3b1104daf1bff898fe5bc3f814811
 * https://github.com/espressif/esp32c3-bt-lib/commit/2a91d90e33b3b1104daf1bff898fe5bc3f814811
 * Upstream date: 2022-09-07 12:18:28 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(2ee0168e)
 * Source: libbtdm_app -> lld_con.o -> lld_con_terminate_max_evt_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_con_terminate_max_evt_update(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1 * 4;
  iVar3 = *(int *)(&lld_con_env + iVar2);
  if ((iVar3 != 0) && (lld_con_term_info[iVar2 + 2] != '\0')) {
    if (param_2 == 0) {
      cVar1 = lld_con_term_info[iVar2 + 3];
      lld_con_term_info[iVar2 + 3] = cVar1 + '\x01';
      if ((5 < (byte)(cVar1 + 1U)) && (*(char *)(iVar3 + 0x8f) != '\x02')) {
        (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar3,1,*(code **)(_r_ip_funcs_p + 0x6b8));
        (**(code **)(_r_ip_funcs_p + 800))(param_1,1,0x16,*(code **)(_r_ip_funcs_p + 800));
        return 1;
      }
    }
    else {
      lld_con_term_info[iVar2 + 3] = 0;
    }
  }
  return 0;
}

