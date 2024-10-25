/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_llcp_trans_timer_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_llcp_trans_timer_set(uint param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  
  uVar2 = param_1 << 8 | 1;
  iVar1 = (param_2 != 0) + 0x100;
  if (param_3 != 0) {
    iVar3 = r_sdk_config_get_opts();
    if (((param_1 < *(byte *)(iVar3 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
       ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
      uVar4 = 4000;
    }
    else {
      uVar4 = *(undefined2 *)(*(int *)(&llc_env + param_1 * 4) + 0x12);
    }
    r_ke_timer_set(iVar1,uVar2,uVar4);
    return;
  }
  r_ke_timer_clear(iVar1,uVar2);
  return;
}

