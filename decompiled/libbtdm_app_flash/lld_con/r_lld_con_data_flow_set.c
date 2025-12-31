/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_data_flow_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_con_data_flow_set(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  uVar3 = 0xc;
  if (iVar1 != 0) {
    r_ble_log_internal_x1
              (0x40e300ef,(uint)*(ushort *)(iVar1 + 0x7c) | param_1 << 0x10 | param_2 << 0x18);
    *(ushort *)(iVar1 + 0x84) = *(ushort *)(iVar1 + 0x84) & 0xffef | (ushort)(param_2 << 4);
    if ((((param_2 != 0) && (r_lld_con_tx_prog(param_1), *(char *)(iVar1 + 0x92) != '\0')) &&
        (*(char *)(iVar1 + 0x8f) == '\0')) &&
       (((*(ushort *)(iVar1 + 0x84) & 1) != 0 && (*(char *)(iVar1 + 0x96) != '\0')))) {
      iVar4 = *(int *)(&lld_con_env + param_1 * 4);
      iVar2 = r_lld_read_clock();
      if (*(uint *)(iVar1 + 100) < (*(int *)(iVar1 + 0x48) - iVar2 & 0xfffffffU)) {
        r_sch_arb_remove(iVar4,0);
        while( true ) {
          if ((*(int *)(iVar1 + 0x48) - iVar2 & 0xfffffffU) <= *(uint *)(iVar1 + 100)) break;
          if (*(short *)(iVar1 + 0x7e) == 0) {
            r_assert_err(0,"lld_con.c",0xf19);
          }
          *(uint *)(iVar1 + 0x48) = *(int *)(iVar1 + 0x48) - *(int *)(iVar1 + 100) & 0xfffffff;
          *(short *)(iVar1 + 0x7e) = *(short *)(iVar1 + 0x7e) + -1;
        }
        r_lld_con_sched_hack(param_1,iVar2,0);
        r_ble_log_internal_x3
                  (0x404300f0,*(undefined4 *)(iVar1 + 0x48),*(undefined4 *)(iVar1 + 0x7c),param_1);
        uVar3 = 0;
        goto _L753;
      }
    }
    uVar3 = 0;
  }
_L753:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar3;
}

