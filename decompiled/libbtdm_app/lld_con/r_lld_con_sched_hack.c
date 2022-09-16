/*
 * Last changed at upstream commit 420ae1726dede6bbd4f3393744a8f3a252330b6a
 * https://github.com/espressif/esp32c3-bt-lib/commit/420ae1726dede6bbd4f3393744a8f3a252330b6a
 * Upstream date: 2022-09-16 21:21:40 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(421c2790)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_sched_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_sched_hack(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  short sVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  
  iVar4 = *(int *)(&lld_con_env + param_1 * 4);
  uVar1 = *(ushort *)(iVar4 + 0x84);
  uVar12 = (uint)DAT_0001101e << 1;
  uVar5 = *(uint *)(iVar4 + 0x48);
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
  uVar6 = *(uint *)(iVar4 + 0x58);
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
    sVar9 = (*(short *)(iVar4 + 0x7c) + *(short *)(iVar4 + 0x7e)) - *(short *)(iVar4 + 0x44);
    uVar6 = uVar5;
    while (sVar9 = sVar9 + -1, sVar9 != -1) {
      uVar6 = uVar6 - *(int *)(iVar4 + 100) & 0xfffffff;
    }
  }
  if ((*(ushort *)(iVar4 + 0x84) & 2) == 0) {
    uVar13 = *(int *)(iVar4 + 100) * 6;
  }
  else {
    uVar13 = *(uint *)(iVar4 + 0x68);
  }
  iVar14 = param_1 * 2;
  iVar15 = 0;
  while ((uVar5 - uVar6 & 0xfffffff) <= uVar13) {
    uVar11 = uVar5;
    if ((*(ushort *)(iVar4 + 0x84) & 1) != 0) {
      iVar10 = *(int *)(iVar4 + 0x50);
      sVar9 = *(short *)(iVar4 + 0x6e);
      iVar15 = (**(code **)(_r_modules_funcs_p + 0x28c))(*(code **)(_r_modules_funcs_p + 0x28c));
      uVar12 = 0x14;
      if (iVar15 == 0) {
        uVar12 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      uVar11 = ((*(ushort *)(iVar4 + 0x7a) + uVar12) * (uVar5 - iVar10 & 0xfffffff)) / 0x640 + 0x40;
      uVar12 = uVar11 * 2;
      if (param_3 != 0) {
        *(undefined2 *)(con_sync_err_cnt + iVar14) = 0;
      }
      if ((*(ushort *)(iVar4 + 0x84) & 2) == 0) {
        uVar12 = uVar12 + (uint)*(ushort *)(iVar4 + 0x70) * 0x271;
_L73:
        bVar3 = true;
      }
      else {
        bVar3 = false;
        if ((*(ushort *)(iVar4 + 0x7c) < 7) &&
           ((param_3 == 0 ||
            ((bVar3 = false, *(ushort *)(iVar4 + 0x7c) == 0 && (*(short *)(iVar4 + 0x98) == -1))))))
        {
          uVar8 = ((int)((uint)*(ushort *)(con_sync_err_cnt + iVar14) *
                         (uint)*(ushort *)(iVar4 + 0x70) * 0x271) >> 1) +
                  (uint)*(ushort *)(iVar4 + 0x70) * 0x271 + uVar12;
          uVar12 = *(int *)(iVar4 + 100) * 0x271;
          if (uVar8 < uVar12) {
            uVar12 = uVar8;
          }
          *(ushort *)(con_sync_err_cnt + iVar14) = *(ushort *)(con_sync_err_cnt + iVar14) + 1;
          goto _L73;
        }
      }
      if (((*(char *)(iVar4 + 0x46) == '\x01') && (*(char *)(iVar4 + 0x42) != '\0')) &&
         (*(char *)(iVar4 + 0x43) == '\0')) {
        uVar12 = uVar12 + (uint)*(ushort *)(iVar4 + 0x40) * 0x271;
      }
      else if ((!bVar3) && (((uint)(*(int *)(iVar4 + 100) * 0x271) >> 1) - 300 <= uVar11)) break;
      uVar8 = (uVar12 >> 1) / 0x271;
      uVar11 = uVar5 - uVar8 & 0xfffffff;
      iVar15 = ((int)sVar9 - (uVar12 >> 1)) + uVar8 * 0x271;
      if (iVar15 < 0) {
        uVar11 = uVar11 - 1 & 0xfffffff;
        iVar15 = iVar15 + 0x271;
      }
      *(int *)(iVar4 + 8) = iVar15;
      *(uint *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x5c) + uVar12;
    }
    *(uint *)(iVar4 + 4) = uVar11;
    iVar10 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar4,*(code **)(_r_ip_funcs_p + 0x6b0));
    if (iVar10 == 0) {
      *(undefined1 *)(iVar4 + 0x8f) = 0;
      *(uint *)(iVar4 + 0x48) = uVar5;
      if ((*(ushort *)(iVar4 + 0x84) & 1) != 0) {
        *(short *)(iVar4 + 0x6c) = (short)iVar15;
        *(uint *)(iVar4 + 0x4c) = uVar12 + (uint)DAT_0001101e * 2;
      }
      return;
    }
    *(char *)(iVar4 + 0x16) = *(char *)(iVar4 + 0x16) + DAT_00011011;
    sVar9 = *(short *)(iVar4 + 0x7e);
    uVar5 = uVar5 + *(int *)(iVar4 + 100) & 0xfffffff;
    *(short *)(iVar4 + 0x7e) = sVar9 + 1;
    if (((*(char *)(iVar4 + 0x46) == '\x01') && (*(char *)(iVar4 + 0x43) == '\0')) &&
       ((ushort)(((sVar9 + 1) - *(short *)(iVar4 + 0x44)) + *(short *)(iVar4 + 0x7c)) < 0x7fff)) {
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
        uVar13 = *(uint *)(iVar4 + 0x68);
        if ((*(ushort *)(iVar4 + 0x84) & 1) == 0) {
          *(undefined1 *)(iVar4 + 0x43) = 1;
        }
      }
      sVar9 = (*(short *)(iVar4 + 0x7c) + *(short *)(iVar4 + 0x7e)) - *(short *)(iVar4 + 0x44);
      uVar6 = uVar5;
      while (sVar9 = sVar9 + -1, sVar9 != -1) {
        uVar6 = uVar6 - *(int *)(iVar4 + 100) & 0xfffffff;
      }
    }
  }
  uVar7 = 8;
  if ((*(ushort *)(iVar4 + 0x84) & 2) == 0) {
    uVar7 = 0x3e;
  }
                    /* WARNING: Could not recover jumptable at 0x00010534. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 800))(param_1,1,uVar7);
  return;
}

