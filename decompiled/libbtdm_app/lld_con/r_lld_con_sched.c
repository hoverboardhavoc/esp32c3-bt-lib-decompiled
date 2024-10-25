/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_sched
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_sched(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  short sVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  
  iVar4 = *(int *)(&lld_con_env + param_1 * 4);
  uVar1 = *(ushort *)(iVar4 + 0x84);
  uVar10 = (uint)DAT_00016026 << 1;
  uVar5 = *(uint *)(iVar4 + 0x48);
  if ((uVar1 & 2) == 0) {
    *(undefined1 *)(iVar4 + 0x16) = 0x1f;
  }
  if (((uVar1 & 3) == 3) && (*(undefined1 *)(iVar4 + 0x96) = 0, param_3 != 0)) {
    uVar2 = *(ushort *)(iVar4 + 0x72);
    if ((uVar2 != 0) &&
       ((((uVar1 & 0x404) == 0x400 && ((uVar1 & 8) == 0)) && (*(char *)(iVar4 + 0x46) == '\0')))) {
      uVar5 = uVar5 + (uint)uVar2 * *(int *)(iVar4 + 100) & 0xfffffff;
      *(ushort *)(iVar4 + 0x7e) = uVar2 + *(short *)(iVar4 + 0x7e);
      *(undefined1 *)(iVar4 + 0x96) = 1;
    }
  }
  for (; (param_2 - uVar5 & 0xfffffff) < 0x7ffffff;
      uVar5 = uVar5 + *(int *)(iVar4 + 100) & 0xfffffff) {
    *(short *)(iVar4 + 0x7e) = *(short *)(iVar4 + 0x7e) + 1;
  }
  uVar13 = *(uint *)(iVar4 + 0x58);
  if (((*(char *)(iVar4 + 0x46) == '\x01') && (*(char *)(iVar4 + 0x43) == '\0')) &&
     ((ushort)((*(short *)(iVar4 + 0x7c) + *(short *)(iVar4 + 0x7e)) - *(short *)(iVar4 + 0x44)) <
      0x7fff)) {
    if (*(char *)(iVar4 + 0x42) == '\0') {
      uVar5 = uVar5 + *(ushort *)(iVar4 + 0x3c) & 0xfffffff;
      if ((uVar1 & 1) != 0) {
        uVar5 = uVar5 + (*(ushort *)(iVar4 + 0x40) >> 1) & 0xfffffff;
      }
      *(undefined4 *)(iVar4 + 100) = *(undefined4 *)(iVar4 + 0x34);
      *(undefined2 *)(iVar4 + 0x72) = *(undefined2 *)(iVar4 + 0x3e);
      *(undefined4 *)(iVar4 + 0x68) = *(undefined4 *)(iVar4 + 0x38);
      *(undefined1 *)(iVar4 + 0x42) = 1;
      if (((uVar1 & 1) == 0) ||
         ((**(code **)(_r_ip_funcs_p + 0x36c))
                    (*(undefined1 *)(iVar4 + 0x8e),*(code **)(_r_ip_funcs_p + 0x36c)),
         (*(ushort *)(iVar4 + 0x84) & 1) == 0)) {
        *(undefined1 *)(iVar4 + 0x43) = 1;
      }
    }
    sVar8 = (*(short *)(iVar4 + 0x7c) + *(short *)(iVar4 + 0x7e)) - *(short *)(iVar4 + 0x44);
    uVar13 = uVar5;
    while (sVar8 = sVar8 + -1, sVar8 != -1) {
      uVar13 = uVar13 - *(int *)(iVar4 + 100) & 0xfffffff;
    }
  }
  if ((*(ushort *)(iVar4 + 0x84) & 2) == 0) {
    uVar12 = *(int *)(iVar4 + 100) * 6;
  }
  else {
    uVar12 = *(uint *)(iVar4 + 0x68);
  }
  iVar14 = 0;
  while ((uVar5 - uVar13 & 0xfffffff) <= uVar12) {
    uVar9 = uVar5;
    if ((*(ushort *)(iVar4 + 0x84) & 1) != 0) {
      iVar11 = *(int *)(iVar4 + 0x50);
      sVar8 = *(short *)(iVar4 + 0x6e);
      iVar14 = (**(code **)(_r_modules_funcs_p + 0x28c))(*(code **)(_r_modules_funcs_p + 0x28c));
      uVar10 = 0x14;
      if (iVar14 == 0) {
        uVar10 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      uVar1 = *(ushort *)(iVar4 + 0x7a);
      iVar14 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
      uVar9 = ((uVar1 + uVar10) * (uVar5 - iVar11 & 0xfffffff)) / 0x640 + 0x40;
      uVar10 = uVar9 * 2;
      if (param_3 != 0) {
        *(undefined2 *)(iVar14 + (param_1 + 0x10) * 2 + 8) = 0;
      }
      if ((*(ushort *)(iVar4 + 0x84) & 2) == 0) {
        uVar10 = uVar10 + (uint)*(ushort *)(iVar4 + 0x70) * 0x271;
_L100:
        bVar3 = true;
      }
      else {
        bVar3 = false;
        if ((*(ushort *)(iVar4 + 0x7c) < 7) &&
           ((param_3 == 0 ||
            ((bVar3 = false, *(ushort *)(iVar4 + 0x7c) == 0 && (*(short *)(iVar4 + 0x98) == -1))))))
        {
          iVar14 = iVar14 + param_1 * 2;
          uVar1 = *(ushort *)(iVar14 + 0x28);
          uVar6 = ((int)((uint)uVar1 * (uint)*(ushort *)(iVar4 + 0x70) * 0x271) >> 1) +
                  (uint)*(ushort *)(iVar4 + 0x70) * 0x271 + uVar10;
          uVar10 = *(int *)(iVar4 + 100) * 0x271;
          if (uVar6 < uVar10) {
            uVar10 = uVar6;
          }
          *(ushort *)(iVar14 + 0x28) = uVar1 + 1;
          goto _L100;
        }
      }
      if (((*(char *)(iVar4 + 0x46) == '\x01') && (*(char *)(iVar4 + 0x42) != '\0')) &&
         (*(char *)(iVar4 + 0x43) == '\0')) {
        uVar10 = uVar10 + (uint)*(ushort *)(iVar4 + 0x40) * 0x271;
      }
      else if ((!bVar3) && (((uint)(*(int *)(iVar4 + 100) * 0x271) >> 1) - 300 <= uVar9)) break;
      uVar6 = (uVar10 >> 1) / 0x271;
      uVar9 = uVar5 - uVar6 & 0xfffffff;
      iVar14 = ((int)sVar8 - (uVar10 >> 1)) + uVar6 * 0x271;
      if (iVar14 < 0) {
        uVar9 = uVar9 - 1 & 0xfffffff;
        iVar14 = iVar14 + 0x271;
      }
      *(int *)(iVar4 + 8) = iVar14;
      *(uint *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x5c) + uVar10;
    }
    *(uint *)(iVar4 + 4) = uVar9;
    iVar11 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar4,*(code **)(_r_ip_funcs_p + 0x6b0));
    if (iVar11 == 0) {
      *(undefined1 *)(iVar4 + 0x8f) = 0;
      *(uint *)(iVar4 + 0x48) = uVar5;
      if ((*(ushort *)(iVar4 + 0x84) & 1) != 0) {
        *(short *)(iVar4 + 0x6c) = (short)iVar14;
        *(uint *)(iVar4 + 0x4c) = uVar10 + (uint)DAT_00016026 * 2;
      }
      return;
    }
    *(char *)(iVar4 + 0x16) = *(char *)(iVar4 + 0x16) + DAT_00016019;
    sVar8 = *(short *)(iVar4 + 0x7e);
    uVar5 = uVar5 + *(int *)(iVar4 + 100) & 0xfffffff;
    *(short *)(iVar4 + 0x7e) = sVar8 + 1;
    if (((*(char *)(iVar4 + 0x46) == '\x01') && (*(char *)(iVar4 + 0x43) == '\0')) &&
       ((ushort)(((sVar8 + 1) - *(short *)(iVar4 + 0x44)) + *(short *)(iVar4 + 0x7c)) < 0x7fff)) {
      if (*(char *)(iVar4 + 0x42) == '\0') {
        uVar5 = uVar5 + *(ushort *)(iVar4 + 0x3c) & 0xfffffff;
        if ((*(ushort *)(iVar4 + 0x84) & 1) != 0) {
          uVar5 = uVar5 + (*(ushort *)(iVar4 + 0x40) >> 1) & 0xfffffff;
        }
        *(undefined4 *)(iVar4 + 100) = *(undefined4 *)(iVar4 + 0x34);
        *(undefined2 *)(iVar4 + 0x72) = *(undefined2 *)(iVar4 + 0x3e);
        *(undefined4 *)(iVar4 + 0x68) = *(undefined4 *)(iVar4 + 0x38);
        if ((*(ushort *)(iVar4 + 0x84) & 1) != 0) {
          (**(code **)(_r_ip_funcs_p + 0x36c))
                    (*(undefined1 *)(iVar4 + 0x8e),*(code **)(_r_ip_funcs_p + 0x36c));
        }
        *(undefined1 *)(iVar4 + 0x42) = 1;
        uVar12 = *(uint *)(iVar4 + 0x68);
        if ((*(ushort *)(iVar4 + 0x84) & 1) == 0) {
          *(undefined1 *)(iVar4 + 0x43) = 1;
        }
      }
      sVar8 = (*(short *)(iVar4 + 0x7c) + *(short *)(iVar4 + 0x7e)) - *(short *)(iVar4 + 0x44);
      uVar13 = uVar5;
      while (sVar8 = sVar8 + -1, sVar8 != -1) {
        uVar13 = uVar13 - *(int *)(iVar4 + 100) & 0xfffffff;
      }
    }
  }
  uVar7 = 8;
  if ((*(ushort *)(iVar4 + 0x84) & 2) == 0) {
    uVar7 = 0x3e;
  }
                    /* WARNING: Could not recover jumptable at 0x0001057a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 800))(param_1,1,uVar7);
  return;
}

