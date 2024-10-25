/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  int iVar3;
  uint uVar4;
  bool bVar5;
  ushort *puVar6;
  int iVar7;
  code *pcVar8;
  int iVar9;
  
  if (8 < param_2) {
    return;
  }
  (&_LANCHOR1)[param_2 * 2] = (char)param_3;
  iVar3 = _r_osi_funcs_p;
  if (param_2 == 8) {
    if (param_3 != 0) goto _L42;
    _LANCHOR0 = 0;
    _LANCHOR3 = 0;
    DAT_00010484 = 0;
    DAT_00010488 = 0;
    pcVar8 = *(code **)(_r_osi_funcs_p + 0xbc);
    uVar4 = 0xffffffff;
  }
  else {
    iVar9 = (uint)(byte)(&_LANCHOR4)[param_2] * 2;
    puVar6 = (ushort *)((int)&_LANCHOR3 + iVar9);
    uVar1 = *puVar6;
    uVar2 = (ushort)(1 << (param_1 & 0x1f));
    uVar4 = (uint)(byte)(&_LANCHOR5)[(byte)(&_LANCHOR4)[param_2]];
    if (param_3 == 1) {
      iVar7 = 0;
      do {
        if ((uVar4 == (byte)(&_LANCHOR5)[iVar7]) && (*(short *)((int)&_LANCHOR3 + iVar7 * 2) != 0))
        {
          bVar5 = true;
          goto _L45;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 != 5);
      bVar5 = false;
_L45:
      _LANCHOR0 = _LANCHOR0 | uVar2;
      *(ushort *)((int)&_LANCHOR3 + iVar9) = uVar2 | uVar1;
      if (bVar5) goto _L42;
      pcVar8 = *(code **)(iVar3 + 0xb8);
    }
    else {
      _LANCHOR0 = _LANCHOR0 & ~uVar2;
      *puVar6 = ~uVar2 & uVar1;
      iVar9 = 0;
      do {
        if ((uVar4 == (byte)(&_LANCHOR5)[iVar9]) && (*(short *)((int)&_LANCHOR3 + iVar9 * 2) != 0))
        goto _L42;
        iVar9 = iVar9 + 1;
      } while (iVar9 != 5);
      if (uVar1 == 0) goto _L42;
      pcVar8 = *(code **)(iVar3 + 0xbc);
    }
  }
  (*pcVar8)(1,uVar4,pcVar8);
_L42:
  iVar3 = coex_hook_check_wifi_sleep();
  if (iVar3 != 0) {
    iVar3 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x00010368. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0xac))(iVar3);
  return;
}

