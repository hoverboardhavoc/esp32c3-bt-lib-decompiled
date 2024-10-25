/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> rf_coexist_hook.o -> bt_rf_coex_hook_st_param_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bt_rf_coex_hook_st_param_set(undefined4 param_1,int param_2,ushort *param_3)

{
  byte bVar1;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  
  bVar2 = false;
  switch(param_2) {
  case 1:
  case 3:
  case 5:
  case 6:
    break;
  case 2:
    uVar7 = (uint)(byte)param_3[4];
    if (uVar7 != 0) {
      uVar7 = __popcountsi2(uVar7);
      uVar7 = uVar7 & 0xff;
    }
    bVar1 = *(byte *)((int)param_3 + 0xb);
    iVar4 = 0;
    if (*(byte *)((int)param_3 + 9) < 4) {
      iVar4 = (int)*(short *)(&_LANCHOR2 + (uint)*(byte *)((int)param_3 + 9) * 2);
    }
    iVar3 = coex_hook_calc_aux_adv_dur(param_3[2],(char)param_3[5]);
    iVar3 = iVar3 + (iVar4 + 0x96) * uVar7 + 300;
    if (iVar3 < 0x1771) {
_L20:
      bVar2 = false;
      goto _L10;
    }
    if (iVar3 < 0xc351) {
      bVar2 = (bVar1 + 1 & 0xff) * *(int *)param_3 * 0x271 <= (uint)(iVar3 * 10);
      goto _L10;
    }
    break;
  case 4:
    iVar4 = coex_hook_calc_aux_adv_dur(param_3[2],(char)param_3[3]);
    if (iVar4 < 0x1771) goto _L20;
    if (iVar4 < 0xc351) {
      bVar2 = (uint)(*(int *)param_3 * 0x4e2) <= (uint)(iVar4 * 10);
      goto _L10;
    }
    break;
  case 7:
    uVar7 = 1;
    if ((char)param_3[3] == '\0') {
      uVar7 = param_3[1] + 1 & 0xffff;
    }
    uVar6 = (uint)param_3[2] * 0x271;
    if (uVar6 < 0x1771) {
      bVar2 = (int)(*param_3 * uVar7 * 0x4e2) < 0x61a9;
    }
    else {
      bVar2 = true;
      if (uVar6 < 0xc351) {
        bVar2 = (int)(*param_3 * uVar7 * 0x4e2) <= (int)((uint)param_3[2] * 0x186a);
      }
    }
    if (2 < _g_bt_plf_log_level) {
      ets_printf("CHK: ACT %d, CONN mst %d, intv %d, ce %d, latency %d\n",param_1,*param_3,
                 param_3[1]);
    }
  default:
    goto _L10;
  }
  bVar2 = true;
_L10:
  iVar4 = _g_bt_plf_log_level;
  (&DAT_0001048d)[param_2 * 2] = bVar2;
  if (2 < iVar4) {
    ets_printf("CHK: st %d sleep %d\n",param_2,bVar2);
  }
  iVar4 = coex_hook_check_wifi_sleep();
  if (iVar4 == 0) {
    if (2 < _g_bt_plf_log_level) {
      ets_printf("UNSLP2\n");
    }
    uVar5 = 0;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_osi_funcs_p + 0xac);
  }
  else {
    if (2 < _g_bt_plf_log_level) {
      ets_printf("SLP2\n");
    }
    uVar5 = 1;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_osi_funcs_p + 0xac);
  }
                    /* WARNING: Could not recover jumptable at 0x000101a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar5);
  return;
}

