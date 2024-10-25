/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_end
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_adv_end(int param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar1 != 0) {
    r_sch_arb_remove(iVar1,0);
    if (*(char *)(iVar1 + 0x95) != '\0') {
      r_sch_arb_remove(iVar1 + 0x34,0);
    }
    if ((*(ushort *)(iVar1 + 0x74) & 8) != 0) {
      r_sch_slice_fg_remove(2);
    }
    if (param_2 != 0) {
      puVar2 = (undefined1 *)r_ke_msg_alloc(0x207,0,0xff,0x3c);
      *puVar2 = (char)param_1;
      puVar2[1] = (char)param_3;
      puVar2[0x35] = 0;
      if ((param_3 != 0) && (param_3 = 0, *(short *)(iVar1 + 0x78) != 0)) {
        param_3 = (uint)*(byte *)(iVar1 + 0x86);
      }
      puVar2[0x38] = (char)param_3;
      r_ke_msg_send();
    }
    r_ke_free(*(undefined4 *)(&lld_adv_env + param_1 * 4));
    *(undefined4 *)(&lld_adv_env + param_1 * 4) = 0;
  }
  return;
}

