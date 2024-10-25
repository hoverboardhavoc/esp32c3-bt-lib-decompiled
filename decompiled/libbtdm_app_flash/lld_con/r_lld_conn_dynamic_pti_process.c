/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_conn_dynamic_pti_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_conn_dynamic_pti_process(uint param_1)

{
  byte bVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar3 = *(int *)(&lld_con_env + param_1 * 4);
  if ((iVar3 != 0) && (iVar4 = r_bt_rf_coex_conn_dynamic_pti_en_get(), iVar4 != 0)) {
    iVar4 = *(int *)(_bt_rf_coex_cfg_p + 0x30);
    if ((*(char *)(iVar3 + 0x46) == '\0') &&
       ((uint)*(byte *)(iVar4 + 4) < (uint)*(ushort *)(iVar3 + 0x7c))) {
      uVar5 = *(uint *)(iVar3 + 100);
      if ((uint)*(byte *)(iVar4 + 6) << 1 < uVar5) {
        if ((uint)*(byte *)(iVar4 + 8) << 1 < uVar5) {
          uVar6 = 0;
          if (uVar5 <= (uint)*(byte *)(iVar4 + 10) << 1) {
            uVar6 = (uint)*(byte *)(iVar4 + 9);
          }
        }
        else {
          uVar6 = (uint)*(byte *)(iVar4 + 7);
        }
      }
      else {
        uVar6 = (uint)*(byte *)(iVar4 + 5);
      }
      if ((int)((uint)*(ushort *)(iVar3 + 0x7c) - (uint)*(ushort *)(iVar3 + 0x98)) <= (int)uVar6) {
        if (0xb < param_1) {
          r_assert_err(0,"lld_con.c",0x293a);
        }
        puVar2 = (uint *)((param_1 + 0x1800c4cb) * 4);
        *puVar2 = *puVar2 & 0x7fffffff;
        return;
      }
    }
    bVar1 = *(byte *)(iVar4 + 3);
    if (0xb < param_1) {
      r_assert_err(0,"lld_con.c",0x298b);
    }
    uVar5 = (uint)bVar1 << 0xc;
    if ((uVar5 & 0xf0000) != 0) {
      r_assert_err(0,"lld_con.c",0x298d);
    }
    puVar2 = (uint *)((param_1 + 0x1800c4cb) * 4);
    *puVar2 = *puVar2 & 0xffff0fff | uVar5;
    bVar1 = *(byte *)(*(int *)(_bt_rf_coex_cfg_p + 0x30) + 2);
    if (0xb < param_1) {
      r_assert_err(0,"lld_con.c",0x29ab);
    }
    uVar5 = (uint)bVar1 << 4;
    if ((uVar5 & 0xffffff0f) != 0) {
      r_assert_err(0,"lld_con.c",0x29ad);
    }
    *puVar2 = *puVar2 & 0xffffff0f | uVar5;
    bVar1 = *(byte *)(*(int *)(_bt_rf_coex_cfg_p + 0x30) + 1);
    if (0xb < param_1) {
      r_assert_err(0,"lld_con.c",0x297b);
    }
    uVar5 = (uint)bVar1 << 0x10;
    if ((uVar5 & 0xf00000) != 0) {
      r_assert_err(0,"lld_con.c",0x297d);
    }
    *puVar2 = *puVar2 & 0xfff0ffff | uVar5;
    bVar1 = **(byte **)(_bt_rf_coex_cfg_p + 0x30);
    if (0xb < param_1) {
      r_assert_err(0,"lld_con.c",0x296a);
    }
    *puVar2 = (uint)bVar1 << 0x14 | *puVar2 & 0xe00fffff;
    if (0xb < param_1) {
      r_assert_err(0,"lld_con.c",0x293a);
    }
    *puVar2 = *puVar2 | 0x80000000;
  }
  return;
}

