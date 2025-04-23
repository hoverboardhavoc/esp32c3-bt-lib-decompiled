/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  undefined1 uVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined1 *puVar8;
  undefined2 *puVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  ushort uVar13;
  char cVar14;
  
  if (param_1 != 0) {
    iVar5 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
    iVar5 = iVar5 + (uint)*(byte *)(param_1 + 0x8e) * 2;
    if (((*(char *)(iVar5 + 0x3d) != '\0') && (*(char *)(param_1 + 0x46) == *(char *)(iVar5 + 0x3d))
        ) && (uVar12 = (uint)*(ushort *)(param_1 + 0x7c) + (uint)*(ushort *)(param_1 + 0x7e) &
                       0xffff, (uVar12 - *(ushort *)(param_1 + 0x44) & 0xffff) < 0x7fff)) {
      bVar1 = *(byte *)(iVar5 + 0x3c);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar11 = (uint)bVar1 * 0xe;
      if (-1 < *(short *)(iVar6 + iVar11)) {
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        sVar3 = *(short *)(iVar11 + 4 + iVar6);
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar4 = *(ushort *)(iVar11 + 2 + iVar6);
        uVar10 = *(byte *)(iVar5 + 0x3d) - 1 & 0xff;
        if (uVar10 < 3) {
          cVar14 = *(char *)((int)&CSWTCH_666 + uVar10);
          uVar13 = (ushort)*(byte *)((int)&CSWTCH_667 + uVar10);
        }
        else {
          (**(code **)(_r_plf_funcs_p + 0xc))
                    (*(undefined1 *)(param_1 + 0x8e),0,"lld_con.c",0x56f,
                     *(code **)(_r_plf_funcs_p + 0xc));
          uVar13 = 0;
          cVar14 = '\0';
        }
        if (((sVar3 == 0) || ((uVar4 & 3) != 3)) ||
           (pcVar7 = (char *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                       (sVar3,*(code **)(_r_plf_funcs_p + 0xbc)), *pcVar7 != cVar14)
           ) {
          if (0 < _g_bt_plf_log_level) {
            puVar8 = (undefined1 *)
                     (**(code **)(_r_plf_funcs_p + 0xbc))(sVar3,*(code **)(_r_plf_funcs_p + 0xbc));
            uVar2 = *puVar8;
            puVar9 = (undefined2 *)
                     (**(code **)(_r_plf_funcs_p + 0xbc))
                               (uVar13 + sVar3,*(code **)(_r_plf_funcs_p + 0xbc));
            ets_printf("llcp check: %u %u %u %u %u\n",uVar12,uVar2,*puVar9,
                       *(undefined1 *)(param_1 + 0x46),*(undefined2 *)(param_1 + 0x44));
          }
          (**(code **)(_r_ip_funcs_p + 0x7d4))
                    (*(undefined1 *)(param_1 + 0x8e),*(code **)(_r_ip_funcs_p + 0x7d4));
        }
        else {
          iVar5 = *(ushort *)(param_1 + 0x72) + 9 + uVar12;
          iVar6 = iVar5 * 0x10000;
          puVar8 = (undefined1 *)
                   (**(code **)(_r_plf_funcs_p + 0xbc))
                             (uVar13 + sVar3,*(code **)(_r_plf_funcs_p + 0xbc));
          *puVar8 = (char)((uint)iVar6 >> 0x10);
          puVar8[1] = (char)((uint)iVar5 >> 8);
          *(short *)(param_1 + 0x44) = (short)((uint)iVar6 >> 0x10);
        }
      }
    }
  }
  r_lld_con_evt_start_cbk(param_1);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar5 + 0x19) == '\x02') {
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

