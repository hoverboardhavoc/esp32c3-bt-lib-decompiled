/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> llc_op_con_upd_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 llc_op_con_upd_ind_handler(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  
  param_2 = param_2 >> 8;
  iVar4 = *(int *)(&llc_env + param_2 * 4);
  iVar1 = r_sdk_config_get_opts();
  if (((param_2 < *(byte *)(iVar1 + 0xd)) && (iVar1 = *(int *)(&llc_env + param_2 * 4), iVar1 != 0))
     && ((*(byte *)(iVar1 + 0x44) & 3) != 3)) {
    iVar1 = r_llc_proc_id_get(param_2,0);
    if ((iVar1 == 0) &&
       (((*(ushort *)(iVar4 + 0x42) & 0x10) == 0 ||
        (iVar1 = r_llc_proc_state_get(param_1), iVar1 != 0)))) {
      iVar1 = r_llc_proc_state_get(param_1);
      if ((iVar1 != 0) && (iVar1 = r_llc_proc_state_get(param_1), iVar1 != 1)) {
        uVar2 = r_llc_proc_state_get(param_1);
        r_assert_param(param_2,uVar2,"llc_con_upd.c",0x690);
      }
      r_llc_proc_reg(param_2,0,param_1);
      uVar2 = r_llc_proc_state_get(param_1);
      r_llc_loc_con_upd_proc_continue_hack(param_2,uVar2,0);
      uVar2 = 1;
    }
    else {
      uVar2 = 2;
    }
  }
  else {
    if (*(char *)(param_1 + 0x2d) == '\0') {
      *(byte *)(iVar4 + 0x45) = *(byte *)(iVar4 + 0x45) & 0x7f;
    }
    else {
      cVar3 = *(char *)(iVar4 + 0x46);
      if (cVar3 == '\0') {
        cVar3 = *(char *)(iVar4 + 0x47);
      }
      r_llc_hci_con_upd_info_send_eco(param_2,cVar3,param_1);
    }
    uVar2 = 0;
  }
  return uVar2;
}

