/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> ke_task.o -> r_ke_task_handler_get_overwrite
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined * r_ke_task_handler_get_overwrite(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  
  uVar1 = *(ushort *)(param_1 + 4);
  if (uVar1 == 0x205) {
    return &lld_per_adv_rx_end_ind_handler_hack;
  }
  if (uVar1 < 0x206) {
    if (uVar1 == 6) {
      return &llm_rpa_renew_to_handler_hack;
    }
    if (uVar1 < 7) {
      if (uVar1 == 3) {
        return &llm_scan_period_to_handler_hack;
      }
    }
    else {
      if (uVar1 == 0x201) {
        return &lld_adv_rep_ind_handler_hack;
      }
      if (uVar1 == 0x203) {
        return &lld_sync_start_req_handler_hack;
      }
    }
  }
  else {
    if (uVar1 == 0x207) {
      return &lld_adv_end_ind_handler_hack;
    }
    if (uVar1 < 0x207) {
      return &lld_scan_end_ind_handler_hack;
    }
    if (uVar1 == 0x20d) {
      return &lld_acl_rx_ind_handler_hack;
    }
    if (uVar1 == 0x213) {
      return &lld_con_estab_ind_handler_hack;
    }
  }
  uVar2 = *(ushort *)(param_1 + 6);
  uVar4 = uVar2 & 0xff;
  if (0x1e < uVar4) {
    r_assert_param(uVar4,"ke_task.c",0x151);
  }
  piVar5 = *(int **)(&ke_task_env + uVar4 * 4);
  if ((*(ushort *)(piVar5 + 2) != 0) &&
     (((uVar2 >> 8 < *(ushort *)(piVar5 + 2) ||
       (r_assert_param((uint)uVar2,uVar1,"ke_task.c",0x159), uVar2 >> 8 < *(ushort *)(piVar5 + 2)))
      && (*piVar5 != 0)))) {
    iVar6 = *(ushort *)((int)piVar5 + 10) - 1;
    if (iVar6 == -1) {
      return (undefined *)0x0;
    }
    while( true ) {
      puVar3 = (ushort *)(iVar6 * 8 + *piVar5);
      if ((*puVar3 == uVar1) || (*puVar3 == 0xffff)) break;
      iVar6 = iVar6 + -1;
      if (iVar6 == -1) {
        return (undefined *)0x0;
      }
    }
    if (*(int *)(puVar3 + 2) == 0) {
      r_assert_err(0,"ke_task.c",0x135);
    }
    return *(undefined **)(puVar3 + 2);
  }
  return (undefined *)0x0;
}

