/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_evt_start_cbk_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_evt_start_cbk_eco(int param_1)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  ushort uVar4;
  short sVar5;
  int iVar6;
  char *pcVar7;
  undefined1 *puVar8;
  undefined2 *puVar9;
  ushort uVar10;
  uint uVar11;
  int iVar12;
  char cVar13;
  int iVar14;
  
  if (param_1 == 0) goto _L560;
  if (*(short *)(param_1 + 0x84) < 0) {
    uVar11 = (uint)*(byte *)(param_1 + 0x8e);
    iVar12 = uVar11 * 4;
    if (-1 < (char)lld_con_fake_rx[iVar12 + 2]) {
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar14 = uVar11 * 0x5a + 0x18;
      uVar10 = *(ushort *)(iVar6 + iVar14);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar4 = *(ushort *)(iVar6 + iVar14);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar6 + iVar14) =
           (ushort)((~((int)(uint)uVar10 >> 0xd) & 1U) << 0xd) | uVar4 & 0xdfff;
      bVar1 = *(byte *)(param_1 + 0x8e);
      bVar2 = *(byte *)(param_1 + 0x90);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(uVar11 * 0x5a + 0x1c + iVar6) =
           ((ushort)bVar1 * 9 + (ushort)bVar2 & 0xff) * 0xe + 0x1400;
    }
    if ((lld_con_fake_rx[iVar12 + 2] & 0x40) == 0) {
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar14 = uVar11 * 0x5a + 0x18;
      uVar10 = *(ushort *)(iVar6 + iVar14);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar4 = *(ushort *)(iVar6 + iVar14);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar6 + iVar14) =
           (ushort)((~((int)(uint)uVar10 >> 0xc) & 1U) << 0xc) | uVar4 & 0xefff;
    }
    if ((*(ushort *)(param_1 + 0x84) >> 0xb & 1) == 0) {
      if (-1 < (char)lld_con_fake_rx[iVar12 + 2]) {
        iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar6 = uVar11 * 0x5a + 0x18;
        uVar10 = *(ushort *)(iVar12 + iVar6);
        iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar12 + iVar6) = uVar10 & 0xbfff | 0x4000;
      }
    }
    else {
      iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar6 = uVar11 * 0x5a + 0x18;
      uVar10 = *(ushort *)(iVar12 + iVar6);
      iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar12 + iVar6) = uVar10 & 0xbfff;
    }
    *(ushort *)(param_1 + 0x84) = *(ushort *)(param_1 + 0x84) & 0x77ff;
  }
  iVar12 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
  iVar12 = iVar12 + (uint)*(byte *)(param_1 + 0x8e) * 2;
  if ((*(char *)(iVar12 + 0x3d) == '\0') || (*(char *)(param_1 + 0x46) != *(char *)(iVar12 + 0x3d)))
  goto _L560;
  uVar11 = (uint)*(ushort *)(param_1 + 0x7c) + (uint)*(ushort *)(param_1 + 0x7e) & 0xffff;
  bVar1 = *(byte *)(iVar12 + 0x3c);
  if (0x7ffe < ((uVar11 - *(ushort *)(param_1 + 0x44)) + 1 & 0xffff)) goto _L560;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar14 = (uint)bVar1 * 0xe;
  if (*(short *)(iVar6 + iVar14) < 0) goto _L560;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  sVar5 = *(short *)(iVar14 + 4 + iVar6);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar4 = *(ushort *)(iVar14 + 2 + iVar6);
  uVar10 = (ushort)*(byte *)(iVar12 + 0x3d);
  if (uVar10 == 1) {
    uVar10 = 10;
_L581:
    cVar13 = '\0';
  }
  else if (uVar10 == 2) {
    uVar10 = 6;
    cVar13 = '\x01';
  }
  else {
    cVar13 = '\x18';
    if (uVar10 != 3) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (*(undefined1 *)(param_1 + 0x8e),0,"lld_con.c",0x63d,
                 *(code **)(_r_plf_funcs_p + 0xc));
      uVar10 = 0;
      goto _L581;
    }
  }
  if (((sVar5 == 0) || ((uVar4 & 3) != 3)) ||
     (pcVar7 = (char *)(**(code **)(_r_plf_funcs_p + 0xbc))(sVar5,*(code **)(_r_plf_funcs_p + 0xbc))
     , *pcVar7 != cVar13)) {
    if (0 < _g_bt_plf_log_level) {
      puVar8 = (undefined1 *)
               (**(code **)(_r_plf_funcs_p + 0xbc))(sVar5,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *puVar8;
      puVar9 = (undefined2 *)
               (**(code **)(_r_plf_funcs_p + 0xbc))
                         (sVar5 + uVar10,*(code **)(_r_plf_funcs_p + 0xbc));
      ets_printf("llcp check: %u %u %u %u %u\n",uVar11,uVar3,*puVar9,*(undefined1 *)(param_1 + 0x46)
                 ,*(undefined2 *)(param_1 + 0x44));
    }
    (**(code **)(_r_ip_funcs_p + 0x7d4))
              (*(undefined1 *)(param_1 + 0x8e),*(code **)(_r_ip_funcs_p + 0x7d4));
  }
  else {
    iVar12 = *(ushort *)(param_1 + 0x72) + 9 + uVar11;
    iVar6 = iVar12 * 0x10000;
    puVar8 = (undefined1 *)
             (**(code **)(_r_plf_funcs_p + 0xbc))(sVar5 + uVar10,*(code **)(_r_plf_funcs_p + 0xbc));
    *puVar8 = (char)((uint)iVar6 >> 0x10);
    puVar8[1] = (char)((uint)iVar12 >> 8);
    *(short *)(param_1 + 0x44) = (short)((uint)iVar6 >> 0x10);
  }
_L560:
  r_lld_con_evt_start_cbk(param_1);
  iVar12 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar12 + 0x19) == '\x02') {
    (**(code **)(_r_ip_funcs_p + 0x9dc))(param_1,*(code **)(_r_ip_funcs_p + 0x9dc));
  }
  if (con_evt_func_cb == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010014. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*con_evt_func_cb)(*(undefined1 *)(param_1 + 0x8e),1);
  return;
}

