/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_terminate_max_evt_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_lld_con_terminate_max_evt_update(uint param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = param_1 * 4;
  iVar1 = *(int *)(&lld_con_env + iVar3);
  if ((iVar1 != 0) && (*(char *)((int)&lld_con_cntl_pkt_info + iVar3 + 2) != '\0')) {
    if (param_2 == 0) {
      bVar2 = *(char *)((int)&lld_con_cntl_pkt_info + iVar3 + 3) + 1;
      *(byte *)((int)&lld_con_cntl_pkt_info + iVar3 + 3) = bVar2;
      if ((5 < bVar2) && (*(char *)(iVar1 + 0x8f) != '\x02')) {
        r_ble_log_internal_x1(0x400300f9,(uint)bVar2 << 8 | param_1);
        r_sch_arb_remove(iVar1,1);
        r_lld_con_cleanup(param_1,1,0x16);
        return 1;
      }
    }
    else {
      *(undefined1 *)((int)&lld_con_cntl_pkt_info + iVar3 + 3) = 0;
    }
  }
  return 0;
}

