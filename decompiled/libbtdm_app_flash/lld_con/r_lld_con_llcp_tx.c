/*
 * Last changed at upstream commit 9b50531537e755792ac827d00d233eab499a0b37
 * https://github.com/espressif/esp32c3-bt-lib/commit/9b50531537e755792ac827d00d233eab499a0b37
 * Upstream date: 2025-12-17 10:51:37 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5106725)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_llcp_tx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_con_llcp_tx(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  uVar3 = 0xc;
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x24) != 0) {
      r_assert_err(0,"lld_con.c",0xe7b);
    }
    *(undefined4 *)(iVar1 + 0x24) = param_2;
    *(ushort *)(iVar1 + 0x84) = *(ushort *)(iVar1 + 0x84) | 8;
    r_lld_con_tx_prog(param_1);
    if (((*(char *)(iVar1 + 0x8f) == '\0') && ((*(ushort *)(iVar1 + 0x84) & 1) != 0)) &&
       (*(char *)(iVar1 + 0x96) != '\0')) {
      uVar4 = *(undefined4 *)(&lld_con_env + param_1 * 4);
      iVar2 = r_lld_read_clock();
      if (*(uint *)(iVar1 + 100) < (*(int *)(iVar1 + 0x48) - iVar2 & 0xfffffffU)) {
        r_sch_arb_remove(uVar4,0);
        while( true ) {
          if ((*(int *)(iVar1 + 0x48) - iVar2 & 0xfffffffU) <= *(uint *)(iVar1 + 100)) break;
          if (*(short *)(iVar1 + 0x7e) == 0) {
            r_assert_err(0,"lld_con.c",0xe97);
          }
          *(uint *)(iVar1 + 0x48) = *(int *)(iVar1 + 0x48) - *(int *)(iVar1 + 100) & 0xfffffff;
          *(short *)(iVar1 + 0x7e) = *(short *)(iVar1 + 0x7e) + -1;
        }
        r_lld_con_sched_hack(param_1,iVar2,0);
        r_ble_log_internal_x3
                  (0x4043008b,*(undefined4 *)(iVar1 + 0x48),*(undefined4 *)(iVar1 + 0x7c),param_1);
        uVar3 = 0;
        goto _L718;
      }
    }
    uVar3 = 0;
  }
_L718:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar3;
}

