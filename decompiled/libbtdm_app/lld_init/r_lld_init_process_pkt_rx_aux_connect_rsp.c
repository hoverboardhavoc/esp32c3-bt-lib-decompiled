/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_process_pkt_rx_aux_connect_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_process_pkt_rx_aux_connect_rsp(int param_1,undefined4 param_2)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  ushort uVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  void *__src;
  code *pcVar10;
  int iVar11;
  
  iVar7 = _lld_init_env;
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar11 = *(int *)(param_1 * 4 + _lld_init_env);
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar8 = (uint)bVar1 * 0x14;
  uVar2 = *(ushort *)(iVar8 + 0x10 + iVar9);
  iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  if ((*(ushort *)(iVar9 + iVar8 + 4) & 0xf) != 8) {
                    /* WARNING: Could not recover jumptable at 0x00010bd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x32a,*(code **)(_r_plf_funcs_p + 8));
    return;
  }
  if (((*(short *)(iVar11 + 0x38) == *(short *)(iVar11 + 0x3a)) && ((uVar2 & 0x300) == 0x300)) &&
     (iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc)),
     (*(ushort *)(iVar8 + 2 + iVar9) >> 0xc & 1) != 0)) {
    iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar3 = *(undefined2 *)(iVar9 + iVar8 + 6);
    iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar8 + 10 + iVar9);
    if ((uVar2 & 0xf000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,1000,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar4 = *(undefined2 *)(iVar8 + 8 + iVar9);
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar5 = *(ushort *)((uint)bVar1 * 0x14 + 0xc + iVar9);
    iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    *(uint *)(iVar7 + 0x54) =
         (((*(ushort *)(&lld_exp_sync_pos_tab + (uint)(*(ushort *)(iVar9 + iVar8 + 6) >> 0xe) * 2) +
           0x96) * -2 - (uVar5 & 0x3ff)) + 0x751) / 0x271 + CONCAT22(uVar2,uVar4) + -1 & 0xfffffff;
    iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    sVar6 = *(short *)(iVar8 + 0xe + iVar9);
    *(short *)(iVar7 + 0x4c) = sVar6;
    if (sVar6 != 0) {
      __src = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                (param_2,*(code **)(_r_plf_funcs_p + 0xbc));
      memcpy((void *)(iVar11 + 0x32),__src,6);
    }
    iVar9 = _r_plf_funcs_p;
    *(byte *)(iVar7 + 0x4e) = (byte)((ushort)uVar3 >> 0xe);
    pcVar10 = *(code **)(iVar9 + 0xbc);
    *(undefined1 *)(iVar7 + 0x58) = 1;
    iVar9 = (*pcVar10)(0x1000,pcVar10);
    uVar2 = *(ushort *)(iVar9 + iVar8 + 4);
    *(undefined1 *)(iVar7 + 0x50) = 1;
    *(undefined1 *)(iVar7 + 0x59) = 1;
    *(byte *)(iVar7 + 0x33) = (byte)(uVar2 >> 6) & 1;
  }
  *(undefined1 *)(iVar11 + 0x3d) = 0;
  return;
}

