/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_terminate_max_evt_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_lld_con_terminate_max_evt_update(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1 * 4;
  iVar3 = *(int *)(&lld_con_env + iVar2);
  if ((iVar3 != 0) && (*(char *)((int)&lld_con_cntl_pkt_info + iVar2 + 2) != '\0')) {
    if (param_2 == 0) {
      cVar1 = *(char *)((int)&lld_con_cntl_pkt_info + iVar2 + 3);
      *(char *)((int)&lld_con_cntl_pkt_info + iVar2 + 3) = cVar1 + '\x01';
      if ((5 < (byte)(cVar1 + 1U)) && (*(char *)(iVar3 + 0x8f) != '\x02')) {
        r_sch_arb_remove(iVar3,1);
        r_lld_con_cleanup(param_1,1,0x16);
        return 1;
      }
    }
    else {
      *(undefined1 *)((int)&lld_con_cntl_pkt_info + iVar2 + 3) = 0;
    }
  }
  return 0;
}

