/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> rf_coexist_hook.o -> bt_rf_coex_hook_st_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bt_rf_coex_hook_st_set(uint param_1,uint param_2,int param_3)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  int iVar7;
  code *pcVar8;
  
  if (8 < param_2) {
    return;
  }
  (&_LANCHOR1)[param_2 * 2] = (char)param_3;
  iVar4 = _r_osi_funcs_p;
  if (param_2 == 8) {
    if (param_3 != 0) goto _L42;
    _LANCHOR0 = 0;
    __LANCHOR3 = 0;
    DAT_0001047c = 0;
    DAT_00010480 = 0;
    pcVar8 = *(code **)(_r_osi_funcs_p + 0xbc);
    uVar5 = 0xffffffff;
  }
  else {
    bVar1 = (&_LANCHOR4)[param_2];
    uVar2 = (&_LANCHOR3)[bVar1];
    uVar3 = (ushort)(1 << (param_1 & 0x1f));
    uVar5 = (uint)(byte)(&_LANCHOR5)[bVar1];
    if (param_3 == 1) {
      iVar7 = 0;
      do {
        if ((uVar5 == (byte)(&_LANCHOR5)[iVar7]) && ((&_LANCHOR3)[iVar7] != 0)) {
          bVar6 = true;
          goto _L45;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 != 5);
      bVar6 = false;
_L45:
      _LANCHOR0 = _LANCHOR0 | uVar3;
      (&_LANCHOR3)[bVar1] = uVar3 | uVar2;
      if (bVar6) goto _L42;
      pcVar8 = *(code **)(iVar4 + 0xb8);
    }
    else {
      _LANCHOR0 = _LANCHOR0 & ~uVar3;
      (&_LANCHOR3)[bVar1] = ~uVar3 & uVar2;
      iVar7 = 0;
      do {
        if ((uVar5 == (byte)(&_LANCHOR5)[iVar7]) && ((&_LANCHOR3)[iVar7] != 0)) goto _L42;
        iVar7 = iVar7 + 1;
      } while (iVar7 != 5);
      if (uVar2 == 0) goto _L42;
      pcVar8 = *(code **)(iVar4 + 0xbc);
    }
  }
  (*pcVar8)(1,uVar5,pcVar8);
_L42:
  iVar4 = coex_hook_check_wifi_sleep();
  if (iVar4 != 0) {
    iVar4 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x00010360. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0xac))(iVar4);
  return;
}

