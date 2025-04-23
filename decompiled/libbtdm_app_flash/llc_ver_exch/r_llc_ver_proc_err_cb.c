/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_ver_exch.o -> r_llc_ver_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_ver_proc_err_cb(int param_1,int param_2,undefined1 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  
  if (param_2 == 0) {
    uVar5 = *param_3;
    iVar1 = *(int *)(&llc_env + param_1 * 4);
    iVar2 = r_llc_proc_get(0);
    iVar3 = r_llc_proc_state_get();
    if (iVar3 == 0) {
      if ((*(ushort *)(iVar1 + 0x42) & 4) == 0) {
        llc_llcp_version_ind_pdu_send(param_1);
        *(ushort *)(iVar1 + 0x42) = *(ushort *)(iVar1 + 0x42) | 8;
        r_llc_proc_state_set(iVar2,param_1,1);
        r_llc_proc_timer_set(param_1,0,1);
        return;
      }
    }
    else if (iVar3 == 1) {
      r_llc_proc_timer_set(param_1,0,0);
    }
    else {
      uVar4 = r_llc_proc_state_get(iVar2);
      r_assert_param(param_1,uVar4,"llc_ver_exch.c",0xbf);
      uVar5 = 0x1f;
    }
    if (*(char *)(iVar2 + 8) != '\0') {
      r_llc_hci_version_info_send(param_1,uVar5,iVar1 + 0x38);
      *(byte *)(iVar1 + 0x45) = *(byte *)(iVar1 + 0x45) & 0xfd;
    }
    r_llc_proc_unreg(param_1,0);
    return;
  }
  if ((param_2 - 1U & 0xff) < 3) {
    return;
  }
  r_assert_param("llc_ver_exch.c",0xe5);
  return;
}

