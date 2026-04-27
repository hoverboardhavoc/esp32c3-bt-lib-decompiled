/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> rf_coexist_hook.o -> bt_rf_coex_hook_st_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bt_rf_coex_hook_st_set(uint param_1,uint param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  code *pcVar7;
  ushort uVar8;
  
  if (8 < param_2) {
    return;
  }
  (&coex_hook_wifi_sleep_flag)[param_2 * 2] = (char)param_3;
  iVar4 = _r_osi_funcs_p;
  uVar6 = (uint)(byte)(&coex_hook_st_group_to_coex_schm_st_tab)
                      [(byte)coex_hook_st_group_tab[param_2]];
  puVar3 = (ushort *)((int)&s_ble_st_group_map + (uint)(byte)coex_hook_st_group_tab[param_2] * 2);
  uVar1 = *puVar3;
  if (param_2 == 8) {
    if (param_3 != 0) goto _L49;
    s_ble_st_group_map = 0;
    DAT_00010500 = 0;
    DAT_00010504 = 0;
    pcVar7 = *(code **)(_r_osi_funcs_p + 0xbc);
    coex_hook_act_id_map = 0;
    uVar6 = 0xffffffff;
  }
  else {
    uVar2 = (ushort)(1 << (param_1 & 0x1f));
    if (param_3 == 1) {
      uVar8 = uVar2 | coex_hook_act_id_map;
      iVar5 = coex_hook_check_coex_schm_st(uVar6);
      coex_hook_act_id_map = uVar8;
      *puVar3 = uVar1 | uVar2;
      if (iVar5 != 0) goto _L49;
      pcVar7 = *(code **)(iVar4 + 0xb8);
    }
    else {
      coex_hook_act_id_map = ~uVar2 & coex_hook_act_id_map;
      *puVar3 = ~uVar2 & uVar1;
      iVar5 = coex_hook_check_coex_schm_st(uVar6);
      if ((uVar1 == 0) || (iVar5 != 0)) goto _L49;
      pcVar7 = *(code **)(iVar4 + 0xbc);
    }
  }
  (*pcVar7)(1,uVar6,pcVar7);
_L49:
  iVar4 = coex_hook_check_wifi_sleep();
  if (iVar4 != 0) {
    iVar4 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x00010428. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0xac))(iVar4,*(code **)(_r_osi_funcs_p + 0xac));
  return;
}

