/*
 * Last changed at upstream commit 7e73ebf92e5aa995065351043c13d2ac0f00772e
 * https://github.com/espressif/esp32c3-bt-lib/commit/7e73ebf92e5aa995065351043c13d2ac0f00772e
 * Upstream date: 2026-05-19 17:43:45 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(bc853c5)
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
  uint *puVar11;
  uint uVar12;
  int iVar13;
  char cVar14;
  int iVar15;
  
  if (param_1 == 0) goto _L564;
  if (*(short *)(param_1 + 0x84) < 0) {
    uVar12 = (uint)*(byte *)(param_1 + 0x8e);
    iVar13 = uVar12 * 4;
    if (-1 < (char)lld_con_fake_rx[iVar13 + 2]) {
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar15 = uVar12 * 0x5a + 0x18;
      uVar10 = *(ushort *)(iVar6 + iVar15);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar4 = *(ushort *)(iVar6 + iVar15);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar6 + iVar15) =
           (ushort)((~((int)(uint)uVar10 >> 0xd) & 1U) << 0xd) | uVar4 & 0xdfff;
      bVar1 = *(byte *)(param_1 + 0x8e);
      bVar2 = *(byte *)(param_1 + 0x90);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(uVar12 * 0x5a + 0x1c + iVar6) =
           ((ushort)bVar1 * 9 + (ushort)bVar2 & 0xff) * 0xe + 0x1400;
    }
    if ((lld_con_fake_rx[iVar13 + 2] & 0x40) == 0) {
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar15 = uVar12 * 0x5a + 0x18;
      uVar10 = *(ushort *)(iVar6 + iVar15);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar4 = *(ushort *)(iVar6 + iVar15);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar6 + iVar15) =
           (ushort)((~((int)(uint)uVar10 >> 0xc) & 1U) << 0xc) | uVar4 & 0xefff;
    }
    if ((*(ushort *)(param_1 + 0x84) >> 0xb & 1) == 0) {
      if (-1 < (char)lld_con_fake_rx[iVar13 + 2]) {
        iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar6 = uVar12 * 0x5a + 0x18;
        uVar10 = *(ushort *)(iVar13 + iVar6);
        iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar13 + iVar6) = uVar10 & 0xbfff | 0x4000;
      }
    }
    else {
      iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar6 = uVar12 * 0x5a + 0x18;
      uVar10 = *(ushort *)(iVar13 + iVar6);
      iVar13 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar13 + iVar6) = uVar10 & 0xbfff;
    }
    *(ushort *)(param_1 + 0x84) = *(ushort *)(param_1 + 0x84) & 0x77ff;
  }
  iVar13 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
  iVar13 = iVar13 + (uint)*(byte *)(param_1 + 0x8e) * 2;
  if ((*(char *)(iVar13 + 0x3d) != '\0') && (*(char *)(param_1 + 0x46) == *(char *)(iVar13 + 0x3d)))
  {
    uVar12 = (uint)*(ushort *)(param_1 + 0x7c) + (uint)*(ushort *)(param_1 + 0x7e) & 0xffff;
    bVar1 = *(byte *)(iVar13 + 0x3c);
    if (((uVar12 - *(ushort *)(param_1 + 0x44)) + 1 & 0xffff) < 0x7fff) {
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar15 = (uint)bVar1 * 0xe;
      if (-1 < *(short *)(iVar6 + iVar15)) {
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        sVar5 = *(short *)(iVar15 + 4 + iVar6);
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar4 = *(ushort *)(iVar15 + 2 + iVar6);
        uVar10 = (ushort)*(byte *)(iVar13 + 0x3d);
        if (uVar10 == 1) {
          uVar10 = 10;
_L593:
          cVar14 = '\0';
        }
        else if (uVar10 == 2) {
          uVar10 = 6;
          cVar14 = '\x01';
        }
        else {
          cVar14 = '\x18';
          if (uVar10 != 3) {
            (**(code **)(_r_plf_funcs_p + 0xc))
                      (*(undefined1 *)(param_1 + 0x8e),0,"lld_con.c",0x646,
                       *(code **)(_r_plf_funcs_p + 0xc));
            uVar10 = 0;
            goto _L593;
          }
        }
        if (((sVar5 == 0) || ((uVar4 & 3) != 3)) ||
           (pcVar7 = (char *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                       (sVar5,*(code **)(_r_plf_funcs_p + 0xbc)), *pcVar7 != cVar14)
           ) {
          if (0 < _g_bt_plf_log_level) {
            puVar8 = (undefined1 *)
                     (**(code **)(_r_plf_funcs_p + 0xbc))(sVar5,*(code **)(_r_plf_funcs_p + 0xbc));
            uVar3 = *puVar8;
            puVar9 = (undefined2 *)
                     (**(code **)(_r_plf_funcs_p + 0xbc))
                               (sVar5 + uVar10,*(code **)(_r_plf_funcs_p + 0xbc));
            ets_printf("llcp check: %u %u %u %u %u\n",uVar12,uVar3,*puVar9,
                       *(undefined1 *)(param_1 + 0x46),*(undefined2 *)(param_1 + 0x44));
          }
          (**(code **)(_r_ip_funcs_p + 0x7d4))
                    (*(undefined1 *)(param_1 + 0x8e),*(code **)(_r_ip_funcs_p + 0x7d4));
        }
        else {
          iVar13 = *(ushort *)(param_1 + 0x72) + 9 + uVar12;
          iVar6 = iVar13 * 0x10000;
          puVar8 = (undefined1 *)
                   (**(code **)(_r_plf_funcs_p + 0xbc))
                             (sVar5 + uVar10,*(code **)(_r_plf_funcs_p + 0xbc));
          *puVar8 = (char)((uint)iVar6 >> 0x10);
          puVar8[1] = (char)((uint)iVar13 >> 8);
          *(short *)(param_1 + 0x44) = (short)((uint)iVar6 >> 0x10);
        }
      }
    }
  }
  if (((*(char *)(param_1 + 0x46) != '\0') &&
      ((ushort)(*(short *)(param_1 + 0x7c) - *(short *)(param_1 + 0x44)) < 0x7fff)) &&
     (*(char *)(param_1 + 0x46) == '\x03')) {
    uVar12 = (uint)*(byte *)(param_1 + 0x8e);
    if ((byte)(*(char *)(param_1 + 0x35) - 2U) < 2) {
      if (0xb < uVar12) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
      }
      puVar11 = (uint *)((uVar12 + 0x1800c4cb) * 4);
      *puVar11 = *puVar11 & 0xfffffff0 | 0xe;
      if (0xb < uVar12) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
      }
      uVar12 = *puVar11 & 0xdfffffff | 0x20000000;
    }
    else {
      if (0xb < uVar12) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x29bb,*(code **)(_r_plf_funcs_p + 8));
      }
      puVar11 = (uint *)((uVar12 + 0x1800c4cb) * 4);
      *puVar11 = *puVar11 & 0xfffffff0;
      if (0xb < uVar12) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x295a,*(code **)(_r_plf_funcs_p + 8));
      }
      uVar12 = *puVar11 & 0xdfffffff;
    }
    *puVar11 = uVar12;
  }
_L564:
  r_lld_con_evt_start_cbk(param_1);
  iVar13 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar13 + 0x19) == '\x02') {
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

